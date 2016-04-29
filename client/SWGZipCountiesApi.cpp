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
SWGZipCountiesApi::zipCountiesGet(QString* zipPrefix) {
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

    



    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGZipCountiesApi::zipCountiesGetCallback);

    worker->execute(&input);
}

void
SWGZipCountiesApi::zipCountiesGetCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    
        QString json(worker->response);
    SWGInline_response_200_2* output = static_cast<SWGInline_response_200_2*>(create(json, QString("SWGInline_response_200_2")));
    

    worker->deleteLater();

    emit zipCountiesGetSignal(output);
    
}
} /* namespace Swagger */