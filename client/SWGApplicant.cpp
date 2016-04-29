
#include "SWGApplicant.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGApplicant::SWGApplicant(QString* json) {
    init();
    this->fromJson(*json);
}

SWGApplicant::SWGApplicant() {
    init();
}

SWGApplicant::~SWGApplicant() {
    this->cleanup();
}

void
SWGApplicant::init() {
    id = NULL;
dob = NULL;
member_id = new QString("");
name = new QString("");
relationship = new QString("");
smoker = false;
ssn = new QString("");
}

void
SWGApplicant::cleanup() {
    
if(dob != NULL) {
        delete dob;
    }
if(member_id != NULL) {
        delete member_id;
    }
if(name != NULL) {
        delete name;
    }
if(relationship != NULL) {
        delete relationship;
    }

if(ssn != NULL) {
        delete ssn;
    }
}

SWGApplicant*
SWGApplicant::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGApplicant::fromJsonObject(QJsonObject &pJson) {
    setValue(&id, pJson["id"], "qint32", "");
setValue(&dob, pJson["dob"], "QDate", "QDate");
setValue(&member_id, pJson["member_id"], "QString", "QString");
setValue(&name, pJson["name"], "QString", "QString");
setValue(&relationship, pJson["relationship"], "QString", "QString");
setValue(&smoker, pJson["smoker"], "bool", "");
setValue(&ssn, pJson["ssn"], "QString", "QString");
}

QString
SWGApplicant::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGApplicant::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    obj->insert("id", QJsonValue(id));

    
    toJsonValue(QString("dob"), dob, obj, QString("QDate"));
    
        

    
    toJsonValue(QString("member_id"), member_id, obj, QString("QString"));
    
        

    
    toJsonValue(QString("name"), name, obj, QString("QString"));
    
        

    
    toJsonValue(QString("relationship"), relationship, obj, QString("QString"));
    
        
obj->insert("smoker", QJsonValue(smoker));

    
    toJsonValue(QString("ssn"), ssn, obj, QString("QString"));
    
        

    return obj;
}

qint32
SWGApplicant::getId() {
    return id;
}
void
SWGApplicant::setId(qint32 id) {
    this->id = id;
}

QDate*
SWGApplicant::getDob() {
    return dob;
}
void
SWGApplicant::setDob(QDate* dob) {
    this->dob = dob;
}

QString*
SWGApplicant::getMemberId() {
    return member_id;
}
void
SWGApplicant::setMemberId(QString* member_id) {
    this->member_id = member_id;
}

QString*
SWGApplicant::getName() {
    return name;
}
void
SWGApplicant::setName(QString* name) {
    this->name = name;
}

QString*
SWGApplicant::getRelationship() {
    return relationship;
}
void
SWGApplicant::setRelationship(QString* relationship) {
    this->relationship = relationship;
}

bool
SWGApplicant::getSmoker() {
    return smoker;
}
void
SWGApplicant::setSmoker(bool smoker) {
    this->smoker = smoker;
}

QString*
SWGApplicant::getSsn() {
    return ssn;
}
void
SWGApplicant::setSsn(QString* ssn) {
    this->ssn = ssn;
}



} /* namespace Swagger */

