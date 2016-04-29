#include "SWGDrugCoverageApi.h"
#include "SWGHelpers.h"
#include "SWGModelFactory.h"

#include <QJsonArray>
#include <QJsonDocument>

namespace Swagger {
SWGDrugCoverageApi::SWGDrugCoverageApi() {}

SWGDrugCoverageApi::~SWGDrugCoverageApi() {}

SWGDrugCoverageApi::SWGDrugCoverageApi(QString host, QString basePath) {
    this->host = host;
    this->basePath = basePath;
}

void
SWGDrugCoverageApi::drugsNdcCoveragesGet(QString* ndc) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/drugs/{ndc}/coverages");

    QString ndcPathParam("{"); ndcPathParam.append("ndc").append("}");
    fullPath.replace(ndcPathParam, stringValue(ndc));


    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "GET");

    



    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGDrugCoverageApi::drugsNdcCoveragesGetCallback);

    worker->execute(&input);
}

void
SWGDrugCoverageApi::drugsNdcCoveragesGetCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    
    QList<SWGDrugCoverage*>* output = new QList<SWGDrugCoverage*>();
    QString json(worker->response);
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonArray jsonArray = doc.array();

    foreach(QJsonValue obj, jsonArray) {
        SWGDrugCoverage* o = new SWGDrugCoverage();
        QJsonObject jv = obj.toObject();
        QJsonObject * ptr = (QJsonObject*)&jv;
        o->fromJsonObject(*ptr);
        output->append(o);
    }

    

    worker->deleteLater();

    emit drugsNdcCoveragesGetSignal(output);
    
}
} /* namespace Swagger */
