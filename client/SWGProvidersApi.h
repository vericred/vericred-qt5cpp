#ifndef _SWG_SWGProvidersApi_H_
#define _SWG_SWGProvidersApi_H_

#include "SWGHttpRequest.h"

#include <QString>
#include "SWGInline_response_200.h"
#include "SWGInline_response_200_1.h"

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

    void providersGet(QString* searchTerm, QString* zipCode, QString* acceptsInsurance, QList<QString*>* hiosIds, QString* page, QString* perPage, QString* radius);
    void providersNpiGet(QString* npi);
    
private:
    void providersGetCallback (HttpRequestWorker * worker);
    void providersNpiGetCallback (HttpRequestWorker * worker);
    
signals:
    void providersGetSignal(SWGInline_response_200* summary);
    void providersNpiGetSignal(SWGInline_response_200_1* summary);
    
};
}
#endif