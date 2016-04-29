#include "SWGPlansApi.h"
#include "SWGHelpers.h"
#include "SWGModelFactory.h"

#include <QJsonArray>
#include <QJsonDocument>

namespace Swagger {
SWGPlansApi::SWGPlansApi() {}

SWGPlansApi::~SWGPlansApi() {}

SWGPlansApi::SWGPlansApi(QString host, QString basePath) {
    this->host = host;
    this->basePath = basePath;
}

void
SWGPlansApi::plansFindPost(SWGQuery query) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/plans/find");



    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "POST");

    
    QString output = query.asJson();
    input.request_body.append(output);
    


    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGPlansApi::plansFindPostCallback);

    worker->execute(&input);
}

void
SWGPlansApi::plansFindPostCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    
    QList<SWGPlan*>* output = new QList<SWGPlan*>();
    QString json(worker->response);
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonArray jsonArray = doc.array();

    foreach(QJsonValue obj, jsonArray) {
        SWGPlan* o = new SWGPlan();
        QJsonObject jv = obj.toObject();
        QJsonObject * ptr = (QJsonObject*)&jv;
        o->fromJsonObject(*ptr);
        output->append(o);
    }

    

    worker->deleteLater();

    emit plansFindPostSignal(output);
    
}
} /* namespace Swagger */
