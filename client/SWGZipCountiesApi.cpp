#include "SWGZipCountiesApi.h"
#include "SWGHelpers.h"
#include "SWGModelFactory.h"

#include <QJsonArray>
#include <QJsonDocument>

namespace Swagger {
SWGZipCountiesApi::SWGZipCountiesApi() {}

SWGZipCountiesApi::~SWGZipCountiesApi() {}

SWGZipCountiesApi::SWGZipCountiesApi(QString host, QString basePath) {
    this->host = host;
    this->basePath = basePath;
}

void
SWGZipCountiesApi::getZipCounties(QString* zipPrefix, QString* vericredApiKey) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/zip_counties");


    if (fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("zipPrefix"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(zipPrefix)));


    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "GET");

    


    // TODO: add header support

    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGZipCountiesApi::getZipCountiesCallback);

    worker->execute(&input);
}

void
SWGZipCountiesApi::getZipCountiesCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    
        QString json(worker->response);
    SWGZipCountyResponse* output = static_cast<SWGZipCountyResponse*>(create(json, QString("SWGZipCountyResponse")));
    

    worker->deleteLater();

    emit getZipCountiesSignal(output);
    
}
} /* namespace Swagger */
