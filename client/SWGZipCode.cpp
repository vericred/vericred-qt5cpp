
#include "SWGZipCode.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGZipCode::SWGZipCode(QString* json) {
    init();
    this->fromJson(*json);
}

SWGZipCode::SWGZipCode() {
    init();
}

SWGZipCode::~SWGZipCode() {
    this->cleanup();
}

void
SWGZipCode::init() {
    code = new QString("");
id = NULL;
}

void
SWGZipCode::cleanup() {
    if(code != NULL) {
        delete code;
    }

}

SWGZipCode*
SWGZipCode::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGZipCode::fromJsonObject(QJsonObject &pJson) {
    setValue(&code, pJson["code"], "QString", "QString");
setValue(&id, pJson["id"], "qint32", "");
}

QString
SWGZipCode::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGZipCode::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("code"), code, obj, QString("QString"));
    
        
obj->insert("id", QJsonValue(id));

    return obj;
}

QString*
SWGZipCode::getCode() {
    return code;
}
void
SWGZipCode::setCode(QString* code) {
    this->code = code;
}

qint32
SWGZipCode::getId() {
    return id;
}
void
SWGZipCode::setId(qint32 id) {
    this->id = id;
}



} /* namespace Swagger */

