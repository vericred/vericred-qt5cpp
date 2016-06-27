#ifndef _SWG_SWGZipCountiesApi_H_
#define _SWG_SWGZipCountiesApi_H_

#include "SWGHttpRequest.h"

#include <QString>
#include "SWGZipCountyResponse.h"

#include <QObject>

namespace Swagger {

class SWGZipCountiesApi: public QObject {
    Q_OBJECT

public:
    SWGZipCountiesApi();
    SWGZipCountiesApi(QString host, QString basePath);
    ~SWGZipCountiesApi();

    QString host;
    QString basePath;

    void getZipCounties(QString* zipPrefix);
    
private:
    void getZipCountiesCallback (HttpRequestWorker * worker);
    
signals:
    void getZipCountiesSignal(SWGZipCountyResponse* summary);
    
};
}
#endif