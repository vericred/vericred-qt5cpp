#include "SWGProvidersApi.h"
#include "SWGHelpers.h"
#include "SWGModelFactory.h"

#include <QJsonArray>
#include <QJsonDocument>

namespace Swagger {
SWGProvidersApi::SWGProvidersApi() {}

SWGProvidersApi::~SWGProvidersApi() {}

SWGProvidersApi::SWGProvidersApi(QString host, QString basePath) {
    this->host = host;
    this->basePath = basePath;
}

void
SWGProvidersApi::getProvider(QString* npi, QString* vericredApiKey) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/providers/{npi}");

    QString npiPathParam("{"); npiPathParam.append("npi").append("}");
    fullPath.replace(npiPathParam, stringValue(npi));


    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "GET");

    


    // TODO: add header support

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGProvidersApi::getProviderCallback);

    worker->execute(&input);
}

void
SWGProvidersApi::getProviderCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    
        QString json(worker->response);
    SWGProviderShowResponse* output = static_cast<SWGProviderShowResponse*>(create(json, QString("SWGProviderShowResponse")));
    

    worker->deleteLater();

    emit getProviderSignal(output);
    
}
void
SWGProvidersApi::getProviders(SWGRequestProvidersSearch body) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/providers/search");



    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "POST");

    
    QString output = body.asJson();
    input.request_body.append(output);
    


    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGProvidersApi::getProvidersCallback);

    worker->execute(&input);
}

void
SWGProvidersApi::getProvidersCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    
        QString json(worker->response);
    SWGProvidersSearchResponse* output = static_cast<SWGProvidersSearchResponse*>(create(json, QString("SWGProvidersSearchResponse")));
    

    worker->deleteLater();

    emit getProvidersSignal(output);
    
}
} /* namespace Swagger */
