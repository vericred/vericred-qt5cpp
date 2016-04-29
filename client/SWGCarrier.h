/*
 * SWGCarrier.h
 * 
 * 
 */

#ifndef SWGCarrier_H_
#define SWGCarrier_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGCarrier: public SWGObject {
public:
    SWGCarrier();
    SWGCarrier(QString* json);
    virtual ~SWGCarrier();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGCarrier* fromJson(QString &jsonString);

    qint32 getId();
    void setId(qint32 id);
QString* getName();
    void setName(QString* name);
QString* getLogoPath();
    void setLogoPath(QString* logo_path);

private:
    qint32 id;
QString* name;
QString* logo_path;
};

} /* namespace Swagger */

#endif /* SWGCarrier_H_ */
