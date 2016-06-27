#include "SWGDrugsApi.h"
#include "SWGHelpers.h"
#include "SWGModelFactory.h"

#include <QJsonArray>
#include <QJsonDocument>

namespace Swagger {
SWGDrugsApi::SWGDrugsApi() {}

SWGDrugsApi::~SWGDrugsApi() {}

SWGDrugsApi::SWGDrugsApi(QString host, QString basePath) {
    this->host = host;
    this->basePath = basePath;
}

void
SWGDrugsApi::getDrugCoverages(QString* ndcPackageCode, QString* audience, QString* stateCode) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/drug_packages/{ndc_package_code}/coverages");

    QString ndcPackageCodePathParam("{"); ndcPackageCodePathParam.append("ndcPackageCode").append("}");
    fullPath.replace(ndcPackageCodePathParam, stringValue(ndcPackageCode));

    if (fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("audience"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(audience)));

    if (fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("stateCode"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(stateCode)));


    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "GET");

    



    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGDrugsApi::getDrugCoveragesCallback);

    worker->execute(&input);
}

void
SWGDrugsApi::getDrugCoveragesCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    
        QString json(worker->response);
    SWGDrugCoverageResponse* output = static_cast<SWGDrugCoverageResponse*>(create(json, QString("SWGDrugCoverageResponse")));
    

    worker->deleteLater();

    emit getDrugCoveragesSignal(output);
    
}
void
SWGDrugsApi::listDrugs(QString* searchTerm) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/drugs");


    if (fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("searchTerm"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(searchTerm)));


    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "GET");

    



    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGDrugsApi::listDrugsCallback);

    worker->execute(&input);
}

void
SWGDrugsApi::listDrugsCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    
        QString json(worker->response);
    SWGDrugSearchResponse* output = static_cast<SWGDrugSearchResponse*>(create(json, QString("SWGDrugSearchResponse")));
    

    worker->deleteLater();

    emit listDrugsSignal(output);
    
}
} /* namespace Swagger */
