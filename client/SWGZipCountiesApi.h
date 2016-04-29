#ifndef _SWG_SWGZipCountiesApi_H_
#define _SWG_SWGZipCountiesApi_H_

#include "SWGHttpRequest.h"

#include <QString>
#include "SWGInline_response_200_2.h"

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

    void zipCountiesGet(QString* zipPrefix);
    
private:
    void zipCountiesGetCallback (HttpRequestWorker * worker);
    
signals:
    void zipCountiesGetSignal(SWGInline_response_200_2* summary);
    
};
}
#endif