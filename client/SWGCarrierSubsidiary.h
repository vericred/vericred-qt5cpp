/*
 * SWGCarrierSubsidiary.h
 * 
 * 
 */

#ifndef SWGCarrierSubsidiary_H_
#define SWGCarrierSubsidiary_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGCarrierSubsidiary: public SWGObject {
public:
    SWGCarrierSubsidiary();
    SWGCarrierSubsidiary(QString* json);
    virtual ~SWGCarrierSubsidiary();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGCarrierSubsidiary* fromJson(QString &jsonString);

    qint32 getId();
    void setId(qint32 id);
QString* getName();
    void setName(QString* name);

private:
    qint32 id;
QString* name;
};

} /* namespace Swagger */

#endif /* SWGCarrierSubsidiary_H_ */
