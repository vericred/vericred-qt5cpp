
#include "SWGMeta.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGMeta::SWGMeta(QString* json) {
    init();
    this->fromJson(*json);
}

SWGMeta::SWGMeta() {
    init();
}

SWGMeta::~SWGMeta() {
    this->cleanup();
}

void
SWGMeta::init() {
    total = NULL;
}

void
SWGMeta::cleanup() {
    
}

SWGMeta*
SWGMeta::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGMeta::fromJsonObject(QJsonObject &pJson) {
    setValue(&total, pJson["total"], "qint32", "");
}

QString
SWGMeta::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGMeta::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("total", QJsonValue(total));

    return obj;
}

qint32
SWGMeta::getTotal() {
    return total;
}
void
SWGMeta::setTotal(qint32 total) {
    this->total = total;
}



} /* namespace Swagger */

