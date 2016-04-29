
#include "SWGInline_response_200_1.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGInline_response_200_1::SWGInline_response_200_1(QString* json) {
    init();
    this->fromJson(*json);
}

SWGInline_response_200_1::SWGInline_response_200_1() {
    init();
}

SWGInline_response_200_1::~SWGInline_response_200_1() {
    this->cleanup();
}

void
SWGInline_response_200_1::init() {
    provider = new SWGProvider();
}

void
SWGInline_response_200_1::cleanup() {
    if(provider != NULL) {
        delete provider;
    }
}

SWGInline_response_200_1*
SWGInline_response_200_1::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGInline_response_200_1::fromJsonObject(QJsonObject &pJson) {
    setValue(&provider, pJson["provider"], "SWGProvider", "SWGProvider");
}

QString
SWGInline_response_200_1::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGInline_response_200_1::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("provider"), provider, obj, QString("SWGProvider"));
    
        

    return obj;
}

SWGProvider*
SWGInline_response_200_1::getProvider() {
    return provider;
}
void
SWGInline_response_200_1::setProvider(SWGProvider* provider) {
    this->provider = provider;
}



} /* namespace Swagger */

