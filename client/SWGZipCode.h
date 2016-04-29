/*
 * SWGZipCode.h
 * 
 * 
 */

#ifndef SWGZipCode_H_
#define SWGZipCode_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGZipCode: public SWGObject {
public:
    SWGZipCode();
    SWGZipCode(QString* json);
    virtual ~SWGZipCode();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGZipCode* fromJson(QString &jsonString);

    QString* getCode();
    void setCode(QString* code);
qint32 getId();
    void setId(qint32 id);

private:
    QString* code;
qint32 id;
};

} /* namespace Swagger */

#endif /* SWGZipCode_H_ */
