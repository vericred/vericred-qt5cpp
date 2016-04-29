/*
 * SWGDrug.h
 * 
 * 
 */

#ifndef SWGDrug_H_
#define SWGDrug_H_

#include <QJsonObject>


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

    QString* getNdc();
    void setNdc(QString* ndc);
QString* getProprietaryName();
    void setProprietaryName(QString* proprietary_name);
QString* getNonProprietaryName();
    void setNonProprietaryName(QString* non_proprietary_name);

private:
    QString* ndc;
QString* proprietary_name;
QString* non_proprietary_name;
};

} /* namespace Swagger */

#endif /* SWGDrug_H_ */
