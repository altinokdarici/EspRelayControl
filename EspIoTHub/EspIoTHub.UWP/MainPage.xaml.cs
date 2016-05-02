using System.Text;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace EspIoTHub.UWP
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public sealed partial class MainPage : Page
	{
		private static IoTHubAmqp.IoTHub iotHub;
		public MainPage()
		{
			this.InitializeComponent();
			iotHub = new IoTHubAmqp.IoTHub("EspRelay", "sb://ihsuproddbres001dednamespace.servicebus.windows.net/", "1000", "iothubowner", "qIuhpEsnkUSvuPu7kwEBc6eyci+pS1JymVwNUruzsig=");



		}

		private async void ToggleSwitch_Toggled(object sender, RoutedEventArgs e)
		{
			ToggleSwitch toggleSwitch = (ToggleSwitch)sender;

			await iotHub.SendCloudToDeviceMessageAsync(toggleSwitch.IsOn ? "0" : "1");
		}
	}
}