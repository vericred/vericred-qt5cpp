/*
 * SWGDrugPackage.h
 * 
 * 
 */

#ifndef SWGDrugPackage_H_
#define SWGDrugPackage_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGDrugPackage: public SWGObject {
public:
    SWGDrugPackage();
    SWGDrugPackage(QString* json);
    virtual ~SWGDrugPackage();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGDrugPackage* fromJson(QString &jsonString);

    QString* getId();
    void setId(QString* id);
QString* getDescription();
    void setDescription(QString* description);

private:
    QString* id;
QString* description;
};

} /* namespace Swagger */

#endif /* SWGDrugPackage_H_ */
