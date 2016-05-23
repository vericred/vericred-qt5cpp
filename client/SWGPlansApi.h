#ifndef _SWG_SWGPlansApi_H_
#define _SWG_SWGPlansApi_H_

#include "SWGHttpRequest.h"

#include "SWGRequestPlanFind.h"
#include "SWGPlanSearchResponse.h"

#include <QObject>

namespace Swagger {

class SWGPlansApi: public QObject {
    Q_OBJECT

public:
    SWGPlansApi();
    SWGPlansApi(QString host, QString basePath);
    ~SWGPlansApi();

    QString host;
    QString basePath;

    void findPlans(SWGRequestPlanFind body);
    
private:
    void findPlansCallback (HttpRequestWorker * worker);
    
signals:
    void findPlansSignal(SWGPlanSearchResponse* summary);
    
};
}
#endif