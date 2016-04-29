#ifndef _SWG_SWGPlansApi_H_
#define _SWG_SWGPlansApi_H_

#include "SWGHttpRequest.h"

#include "SWGPlan.h"
#include "SWGQuery.h"

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

    void plansFindPost(SWGQuery query);
    
private:
    void plansFindPostCallback (HttpRequestWorker * worker);
    
signals:
    void plansFindPostSignal(QList<SWGPlan*>* summary);
    
};
}
#endif