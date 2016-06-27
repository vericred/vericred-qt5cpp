#ifndef _SWG_SWGProvidersApi_H_
#define _SWG_SWGProvidersApi_H_

#include "SWGHttpRequest.h"

#include <QString>
#include "SWGProviderShowResponse.h"
#include "SWGRequestProvidersSearch.h"
#include "SWGProvidersSearchResponse.h"

#include <QObject>

namespace Swagger {

class SWGProvidersApi: public QObject {
    Q_OBJECT

public:
    SWGProvidersApi();
    SWGProvidersApi(QString host, QString basePath);
    ~SWGProvidersApi();

    QString host;
    QString basePath;

    void getProvider(QString* npi);
    void getProviders(SWGRequestProvidersSearch body);
    
private:
    void getProviderCallback (HttpRequestWorker * worker);
    void getProvidersCallback (HttpRequestWorker * worker);
    
signals:
    void getProviderSignal(SWGProviderShowResponse* summary);
    void getProvidersSignal(SWGProvidersSearchResponse* summary);
    
};
}
#endif