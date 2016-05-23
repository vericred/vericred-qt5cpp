#ifndef _SWG_SWGDrugsApi_H_
#define _SWG_SWGDrugsApi_H_

#include "SWGHttpRequest.h"

#include <QString>
#include "SWGDrugCoverageResponse.h"
#include "SWGDrugSearchResponse.h"

#include <QObject>

namespace Swagger {

class SWGDrugsApi: public QObject {
    Q_OBJECT

public:
    SWGDrugsApi();
    SWGDrugsApi(QString host, QString basePath);
    ~SWGDrugsApi();

    QString host;
    QString basePath;

    void getDrugCoverages(QString* ndcPackageCode, QString* audience, QString* stateCode, QString* vericredApiKey);
    void listDrugs(QString* searchTerm, QString* vericredApiKey);
    
private:
    void getDrugCoveragesCallback (HttpRequestWorker * worker);
    void listDrugsCallback (HttpRequestWorker * worker);
    
signals:
    void getDrugCoveragesSignal(SWGDrugCoverageResponse* summary);
    void listDrugsSignal(SWGDrugSearchResponse* summary);
    
};
}
#endif