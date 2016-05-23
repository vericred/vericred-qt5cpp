/*
 * SWGDrug.h
 * 
 * 
 */

#ifndef SWGDrug_H_
#define SWGDrug_H_

#include <QJsonObject>


#include <QList>
#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGDrug: public SWGObject {
public:
    SWGDrug();
    SWGDrug(QString* json);
    virtual ~SWGDrug();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGDrug* fromJson(QString &jsonString);

    QString* getId();
    void setId(QString* id);
QString* getProprietaryName();
    void setProprietaryName(QString* proprietary_name);
QString* getNonProprietaryName();
    void setNonProprietaryName(QString* non_proprietary_name);
QList<QString*>* getDrugPackageIds();
    void setDrugPackageIds(QList<QString*>* drug_package_ids);

private:
    QString* id;
QString* proprietary_name;
QString* non_proprietary_name;
QList<QString*>* drug_package_ids;
};

} /* namespace Swagger */

#endif /* SWGDrug_H_ */
