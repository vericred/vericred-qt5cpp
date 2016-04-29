
#include "SWGDrug.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace Swagger {


SWGDrug::SWGDrug(QString* json) {
    init();
    this->fromJson(*json);
}

SWGDrug::SWGDrug() {
    init();
}

SWGDrug::~SWGDrug() {
    this->cleanup();
}

void
SWGDrug::init() {
    ndc = new QString("");
proprietary_name = new QString("");
non_proprietary_name = new QString("");
}

void
SWGDrug::cleanup() {
    if(ndc != NULL) {
        delete ndc;
    }
if(proprietary_name != NULL) {
        delete proprietary_name;
    }
if(non_proprietary_name != NULL) {
        delete non_proprietary_name;
    }
}

SWGDrug*
SWGDrug::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGDrug::fromJsonObject(QJsonObject &pJson) {
    setValue(&ndc, pJson["ndc"], "QString", "QString");
setValue(&proprietary_name, pJson["proprietary_name"], "QString", "QString");
setValue(&non_proprietary_name, pJson["non_proprietary_name"], "QString", "QString");
}

QString
SWGDrug::asJson ()
{
    QJsonObject* obj = this->asJsonObject();
    
    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    return QString(bytes);
}

QJsonObject*
SWGDrug::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    
    
    toJsonValue(QString("ndc"), ndc, obj, QString("QString"));
    
        

    
    toJsonValue(QString("proprietary_name"), proprietary_name, obj, QString("QString"));
    
        

    
    toJsonValue(QString("non_proprietary_name"), non_proprietary_name, obj, QString("QString"));
    
        

    return obj;
}

QString*
SWGDrug::getNdc() {
    return ndc;
}
void
SWGDrug::setNdc(QString* ndc) {
    this->ndc = ndc;
}

QString*
SWGDrug::getProprietaryName() {
    return proprietary_name;
}
void
SWGDrug::setProprietaryName(QString* proprietary_name) {
    this->proprietary_name = proprietary_name;
}

QString*
SWGDrug::getNonProprietaryName() {
    return non_proprietary_name;
}
void
SWGDrug::setNonProprietaryName(QString* non_proprietary_name) {
    this->non_proprietary_name = non_proprietary_name;
}



} /* namespace Swagger */

