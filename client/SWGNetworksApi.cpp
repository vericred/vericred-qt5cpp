#include "SWGNetworksApi.h"
#include "SWGHelpers.h"
#include "SWGModelFactory.h"

#include <QJsonArray>
#include <QJsonDocument>

namespace Swagger {
SWGNetworksApi::SWGNetworksApi() {}

SWGNetworksApi::~SWGNetworksApi() {}

SWGNetworksApi::SWGNetworksApi(QString host, QString basePath) {
    this->host = host;
    this->basePath = basePath;
}

void
SWGNetworksApi::listNetworks(QString* carrierId, qint32 page, qint32 perPage) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/networks");


    if (fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("carrierId"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(carrierId)));

    if (fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("page"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(page)));

    if (fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("perPage"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(perPage)));


    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "GET");

    



    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGNetworksApi::listNetworksCallback);

    worker->execute(&input);
}

void
SWGNetworksApi::listNetworksCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    
        QString json(worker->response);
    SWGNetworkSearchResponse* output = static_cast<SWGNetworkSearchResponse*>(create(json, QString("SWGNetworkSearchResponse")));
    

    worker->deleteLater();

    emit listNetworksSignal(output);
    
}
} /* namespace Swagger */
