![Pidgin logo](https://raw.githubusercontent.com/dadecoza/pidgin-meshtastic/refs/heads/main/nsis/pidgin-meshtastic.ico)

# a Meshtastic plugin for Pidgin

Make sure you already have [Pidgin](https://pidgin.im/install/) installed.

The Windows installer for the plugin is available under the [latest release](https://github.com/dadecoza/pidgin-meshtastic/releases/).


## Build

### Debian
NOTE: You need to have sources added to /etc/apt/sources.list. You either have to uncomment or add the deb-src entry.

```shell
sudo apt-get update
sudo apt-get build-dep pidgin
git clone https://github.com/dadecoza/pidgin-meshtastic.git --recursive
make
```
Copy the library and pixmaps to the appropriate locations. The file locations might differ depending on your distro.
 ```shell
sudo cp libmeshtastic.so /usr/lib/purple-2
sudo cp -r pixmaps /usr/share
 ```

### Windows
Follow the [Pidgin for Windows Build Instructions](https://developer.pidgin.im/wiki/BuildingWinPidgin.html) and navigate to $PIDGIN_DEV_ROOT .
```shell
git clone https://github.com/dadecoza/pidgin-meshtastic.git --recursive
cd pidgin-meshtastic
make -f Makefile.mingw
```
 * Copy libmeshtastic.dll to C:\Program Files (x86)\Pidgin\Plugins
 * Copy the pixmaps directory to C:\Program Files (x86)\Pidgin

# Adding the account
![Account screenshot](https://dade.co.za/images/account.png)
* *Protocol*: Meshtastic
* *Username*: this can be anything, your radio will update the username once connected
* *COM port or IP address*: Typically "COMx" on Windows, or "/dev/ttyUSBx" on Linux. It can also be a valid IPv4 address for socket connections.
* *Local Alias*: Can be left empty, it will populate on first connect.
