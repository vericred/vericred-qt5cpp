/*
 * SWGMeta.h
 * 
 * 
 */

#ifndef SWGMeta_H_
#define SWGMeta_H_

#include <QJsonObject>



#include "SWGObject.h"


namespace Swagger {

class SWGMeta: public SWGObject {
public:
    SWGMeta();
    SWGMeta(QString* json);
    virtual ~SWGMeta();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGMeta* fromJson(QString &jsonString);

    qint32 getTotal();
    void setTotal(qint32 total);

private:
    qint32 total;
};

} /* namespace Swagger */

#endif /* SWGMeta_H_ */
