/*
 * SWGBase.h
 * 
 * 
 */

#ifndef SWGBase_H_
#define SWGBase_H_

#include <QJsonObject>


#include "SWGMeta.h"

#include "SWGObject.h"


namespace Swagger {

class SWGBase: public SWGObject {
public:
    SWGBase();
    SWGBase(QString* json);
    virtual ~SWGBase();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGBase* fromJson(QString &jsonString);

    SWGMeta* getMeta();
    void setMeta(SWGMeta* meta);

private:
    SWGMeta* meta;
};

} /* namespace Swagger */

#endif /* SWGBase_H_ */
