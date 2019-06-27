#include<iostream>
#include<pthread.h>
#include <unistd.h>

using namespace std;
class NetworkManager;
class NetworkDevice
{
public:
    NetworkDevice(NetworkManager *callback = NULL);
    virtual ~NetworkDevice();
    virtual bool sendMessage();
private:
    NetworkManager *_callback;
};
NetworkDevice::NetworkDevice( NetworkManager *callback): _callback(callback)
{
    cout<<"create NetworkDevice"<<endl;
}

NetworkDevice::~NetworkDevice()
{
    _callback = NULL;
}

bool NetworkDevice::sendMessage()
{
    cout<<"NetworkDevice::sendMessage"<<endl;

    return true;
}
class NetworkManager
{
public:

    static NetworkManager &instance()
    {
        static NetworkManager instance;
        return instance;
    }

    virtual ~NetworkManager();
    bool sendMessage();

private:
    NetworkManager();
    NetworkDevice *_networkDevice;
};
static void *thread_wifi_scan(void *arg)
{
while(1)
{
 NetworkManager::instance().sendMessage();
 sleep(1);
}
}
void WifiCfgInit()
{


    pthread_t id;


    pthread_create(&id, NULL, thread_wifi_scan, NULL);
}
NetworkManager::NetworkManager()
{


    cout<<"NetworkManager"<<endl;
    _networkDevice = new NetworkDevice(this);
    WifiCfgInit();
}

NetworkManager::~NetworkManager()
{
    if (_networkDevice)
    {
        delete _networkDevice;
        _networkDevice = NULL;
    }
}
bool NetworkManager::sendMessage()
{
    if (_networkDevice)
    {
//         DEV_LOGI("sendMessage type=%d", message.type);
        _networkDevice->sendMessage();
    }

    // TODO uninit
}

int main()
{
	cout<<"hello work"<<endl;
	NetworkManager::instance();
	while(1)
{
}
	return 0;
}
