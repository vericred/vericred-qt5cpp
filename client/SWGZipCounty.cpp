
#include "SWGZipCounty.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGZipCounty::SWGZipCounty(QString* json) {
    init();
    this->fromJson(*json);
}

SWGZipCounty::SWGZipCounty() {
    init();
}

SWGZipCounty::~SWGZipCounty() {
    this->cleanup();
}

void
SWGZipCounty::init() {
    county_id = NULL;
id = NULL;
zip_code_id = NULL;
}

void
SWGZipCounty::cleanup() {
    


}

SWGZipCounty*
SWGZipCounty::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGZipCounty::fromJsonObject(QJsonObject &pJson) {
    setValue(&county_id, pJson["county_id"], "qint32", "");
setValue(&id, pJson["id"], "qint32", "");
setValue(&zip_code_id, pJson["zip_code_id"], "qint32", "");
}

QString
SWGZipCounty::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGZipCounty::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("county_id", QJsonValue(county_id));
obj->insert("id", QJsonValue(id));
obj->insert("zip_code_id", QJsonValue(zip_code_id));

    return obj;
}

qint32
SWGZipCounty::getCountyId() {
    return county_id;
}
void
SWGZipCounty::setCountyId(qint32 county_id) {
    this->county_id = county_id;
}

qint32
SWGZipCounty::getId() {
    return id;
}
void
SWGZipCounty::setId(qint32 id) {
    this->id = id;
}

qint32
SWGZipCounty::getZipCodeId() {
    return zip_code_id;
}
void
SWGZipCounty::setZipCodeId(qint32 zip_code_id) {
    this->zip_code_id = zip_code_id;
}



} /* namespace Swagger */

