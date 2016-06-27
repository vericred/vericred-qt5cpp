#ifndef _SWG_SWGNetworksApi_H_
#define _SWG_SWGNetworksApi_H_

#include "SWGHttpRequest.h"

#include <QString>
#include "SWGNetworkSearchResponse.h"

#include <QObject>

namespace Swagger {

class SWGNetworksApi: public QObject {
    Q_OBJECT

public:
    SWGNetworksApi();
    SWGNetworksApi(QString host, QString basePath);
    ~SWGNetworksApi();

    QString host;
    QString basePath;

    void listNetworks(QString* carrierId, qint32 page, qint32 perPage);
    
private:
    void listNetworksCallback (HttpRequestWorker * worker);
    
signals:
    void listNetworksSignal(SWGNetworkSearchResponse* summary);
    
};
}
#endif