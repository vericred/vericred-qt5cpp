#ifndef _SWG_SWGDrugCoverageApi_H_
#define _SWG_SWGDrugCoverageApi_H_

#include "SWGHttpRequest.h"

#include <QString>
#include "SWGDrugCoverage.h"

#include <QObject>

namespace Swagger {

class SWGDrugCoverageApi: public QObject {
    Q_OBJECT

public:
    SWGDrugCoverageApi();
    SWGDrugCoverageApi(QString host, QString basePath);
    ~SWGDrugCoverageApi();

    QString host;
    QString basePath;

    void drugsNdcCoveragesGet(QString* ndc);
    
private:
    void drugsNdcCoveragesGetCallback (HttpRequestWorker * worker);
    
signals:
    void drugsNdcCoveragesGetSignal(QList<SWGDrugCoverage*>* summary);
    
};
}
#endif