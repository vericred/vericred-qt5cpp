
#include "SWGBase.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGBase::SWGBase(QString* json) {
    init();
    this->fromJson(*json);
}

SWGBase::SWGBase() {
    init();
}

SWGBase::~SWGBase() {
    this->cleanup();
}

void
SWGBase::init() {
    meta = new SWGMeta();
}

void
SWGBase::cleanup() {
    if(meta != NULL) {
        delete meta;
    }
}

SWGBase*
SWGBase::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGBase::fromJsonObject(QJsonObject &pJson) {
    setValue(&meta, pJson["meta"], "SWGMeta", "SWGMeta");
}

QString
SWGBase::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGBase::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("meta"), meta, obj, QString("SWGMeta"));
    
        

    return obj;
}

SWGMeta*
SWGBase::getMeta() {
    return meta;
}
void
SWGBase::setMeta(SWGMeta* meta) {
    this->meta = meta;
}



} /* namespace Swagger */

