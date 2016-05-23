/*
 * SWGZipCountyBulk.h
 * 
 * 
 */

#ifndef SWGZipCountyBulk_H_
#define SWGZipCountyBulk_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGZipCountyBulk: public SWGObject {
public:
    SWGZipCountyBulk();
    SWGZipCountyBulk(QString* json);
    virtual ~SWGZipCountyBulk();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGZipCountyBulk* fromJson(QString &jsonString);

    qint32 getId();
    void setId(qint32 id);
QString* getRatingAreaId();
    void setRatingAreaId(QString* rating_area_id);
QString* getCountyId();
    void setCountyId(QString* county_id);
QString* getZipCodeId();
    void setZipCodeId(QString* zip_code_id);

private:
    qint32 id;
QString* rating_area_id;
QString* county_id;
QString* zip_code_id;
};

} /* namespace Swagger */

#endif /* SWGZipCountyBulk_H_ */
