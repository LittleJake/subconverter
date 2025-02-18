#ifndef PROXY_H_INCLUDED
#define PROXY_H_INCLUDED

#include <cstdint>
#include <string>

#include "../../utils/tribool.h"

using String = std::string;

enum ProxyType
{
    Unknow,
    Shadowsocks,
    ShadowsocksR,
    VMess,
    VLESS,
    Hysteria,
    Hysteria2,
    Wireguard,
    Trojan,
    Snell,
    HTTP,
    HTTPS,
    SOCKS5
};

inline String getProxyTypeName(int type)
{
    switch(type)
    {
    case ProxyType::Shadowsocks:
        return "SS";
    case ProxyType::ShadowsocksR:
        return "SSR";
    case ProxyType::VMess:
        return "VMess";
    case ProxyType::VLESS:
        return "VLESS";
    case ProxyType::Hysteria:
        return "Hysteria";
    case ProxyType::Hysteria2:
        return "Hysteria2";
    case ProxyType::Trojan:
        return "Trojan";
    case ProxyType::Snell:
        return "Snell";
    case ProxyType::HTTP:
        return "HTTP";
    case ProxyType::HTTPS:
        return "HTTPS";
    case ProxyType::SOCKS5:
        return "SOCKS5";
    default:
        return "Unknown";
    }
}

struct Proxy
{
    int Type = ProxyType::Unknow;
    uint32_t Id = 0;
    uint32_t GroupId = 0;
    String Group;
    String Remark;
    String Hostname;
    uint16_t Port = 0;

    String Username;
    String Password;
    String EncryptMethod;
    String Plugin;
    String PluginOption;
    String Protocol;
    String ProtocolParam;
    String OBFS;
    String OBFSParam;
    String UserId;
    uint16_t AlterId = 0;
    String TransferProtocol;
    String FakeType;
    bool TLSSecure = false;

    String Flow;
    bool FlowShow = false;

    String Host;
    String Path;
    String Edge;

    String QUICSecure;
    String QUICSecret;
    String GRPCServiceName;
    String GRPCMode;

    tribool UDP;
    tribool XUDP;
    tribool TCPFastOpen;
    tribool AllowInsecure;
    tribool TLS13;

    uint16_t SnellVersion = 0;
    String ServerName;

    String Auth;
    String Alpn;
    String UpMbps;
    String DownMbps;
    String Insecure;
    String MPort;

    String Fingerprint;
    String PublicKey;
    String ShortId;

    String PrivateKey;
    String PreSharedKey;
    String IP;
    String IPv6;
};

#define SS_DEFAULT_GROUP "SSProvider"
#define SSR_DEFAULT_GROUP "SSRProvider"
#define V2RAY_DEFAULT_GROUP "V2RayProvider"
#define XRAY_DEFAULT_GROUP "XRayProvider"
#define HYSTERIA_DEFAULT_GROUP "HysteriaProvider"
#define WIREGUARD_DEFAULT_GROUP "WireguardProvider"
#define SOCKS_DEFAULT_GROUP "SocksProvider"
#define HTTP_DEFAULT_GROUP "HTTPProvider"
#define TROJAN_DEFAULT_GROUP "TrojanProvider"
#define SNELL_DEFAULT_GROUP "SnellProvider"

#endif // PROXY_H_INCLUDED
