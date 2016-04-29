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
SWGProvidersApi::providersGet(QString* searchTerm, QString* zipCode, QString* acceptsInsurance, QList<QString*>* hiosIds, QString* page, QString* perPage, QString* radius) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/providers");


    if (fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("acceptsInsurance"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(acceptsInsurance)));



    if (hiosIds->size() > 0) {
      if (QString("csv").indexOf("multi") == 0) {
        foreach(QString* t, *hiosIds) {
          if (fullPath.indexOf("?") > 0)
            fullPath.append("&");
          else 
            fullPath.append("?");
          fullPath.append("hiosIds=").append(stringValue(t));
        }
      }
      else if (QString("csv").indexOf("ssv") == 0) {
        if (fullPath.indexOf("?") > 0)
          fullPath.append("&");
        else 
          fullPath.append("?");
        fullPath.append("hiosIds=");
        qint32 count = 0;
        foreach(QString* t, *hiosIds) {
          if (count > 0) {
            fullPath.append(" ");
          }
          fullPath.append(stringValue(t));
        }
      }
      else if (QString("csv").indexOf("tsv") == 0) {
        if (fullPath.indexOf("?") > 0)
          fullPath.append("&");
        else 
          fullPath.append("?");
        fullPath.append("hiosIds=");
        qint32 count = 0;
        foreach(QString* t, *hiosIds) {
          if (count > 0) {
            fullPath.append("\t");
          }
          fullPath.append(stringValue(t));
        }
      }
    }

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

    if (fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("radius"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(radius)));

    if (fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("searchTerm"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(searchTerm)));

    if (fullPath.indexOf("?") > 0) 
      fullPath.append("&");
    else 
      fullPath.append("?");
    fullPath.append(QUrl::toPercentEncoding("zipCode"))
        .append("=")
        .append(QUrl::toPercentEncoding(stringValue(zipCode)));


    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "GET");

    



    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGProvidersApi::providersGetCallback);

    worker->execute(&input);
}

void
SWGProvidersApi::providersGetCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    
        QString json(worker->response);
    SWGInline_response_200* output = static_cast<SWGInline_response_200*>(create(json, QString("SWGInline_response_200")));
    

    worker->deleteLater();

    emit providersGetSignal(output);
    
}
void
SWGProvidersApi::providersNpiGet(QString* npi) {
    QString fullPath;
    fullPath.append(this->host).append(this->basePath).append("/providers/{npi}");

    QString npiPathParam("{"); npiPathParam.append("npi").append("}");
    fullPath.replace(npiPathParam, stringValue(npi));


    HttpRequestWorker *worker = new HttpRequestWorker();
    HttpRequestInput input(fullPath, "GET");

    



    connect(worker,
            &HttpRequestWorker::on_execution_finished,
            this,
            &SWGProvidersApi::providersNpiGetCallback);

    worker->execute(&input);
}

void
SWGProvidersApi::providersNpiGetCallback(HttpRequestWorker * worker) {
    QString msg;
    if (worker->error_type == QNetworkReply::NoError) {
        msg = QString("Success! %1 bytes").arg(worker->response.length());
    }
    else {
        msg = "Error: " + worker->error_str;
    }

    
        QString json(worker->response);
    SWGInline_response_200_1* output = static_cast<SWGInline_response_200_1*>(create(json, QString("SWGInline_response_200_1")));
    

    worker->deleteLater();

    emit providersNpiGetSignal(output);
    
}
} /* namespace Swagger */
