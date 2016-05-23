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
SWGPlansApi::findPlans(SWGRequestPlanFind body) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/plans/search");



    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "POST");

    
    QString output = body.asJson();
    input.request_body.append(output);
    


    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGPlansApi::findPlansCallback);

    worker->execute(&input);
}

void
SWGPlansApi::findPlansCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    
        QString json(worker->response);
    SWGPlanSearchResponse* output = static_cast<SWGPlanSearchResponse*>(create(json, QString("SWGPlanSearchResponse")));
    

    worker->deleteLater();

    emit findPlansSignal(output);
    
}
} /* namespace Swagger */
