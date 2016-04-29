/*
 * SWGZipCounty.h
 * 
 * 
 */

#ifndef SWGZipCounty_H_
#define SWGZipCounty_H_

#include <QJsonObject>



#include "SWGObject.h"


namespace Swagger {

class SWGZipCounty: public SWGObject {
public:
    SWGZipCounty();
    SWGZipCounty(QString* json);
    virtual ~SWGZipCounty();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGZipCounty* fromJson(QString &jsonString);

    qint32 getCountyId();
    void setCountyId(qint32 county_id);
qint32 getId();
    void setId(qint32 id);
qint32 getZipCodeId();
    void setZipCodeId(qint32 zip_code_id);

private:
    qint32 county_id;
qint32 id;
qint32 zip_code_id;
};

} /* namespace Swagger */

#endif /* SWGZipCounty_H_ */
