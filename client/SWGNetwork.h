/*
 * SWGNetwork.h
 * 
 * 
 */

#ifndef SWGNetwork_H_
#define SWGNetwork_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"


namespace Swagger {

class SWGNetwork: public SWGObject {
public:
    SWGNetwork();
    SWGNetwork(QString* json);
    virtual ~SWGNetwork();
    void init();
    void cleanup();

    QString asJson ();
    QJsonObject* asJsonObject();
    void fromJsonObject(QJsonObject &json);
    SWGNetwork* fromJson(QString &jsonString);

    qint32 getId();
    void setId(qint32 id);
QString* getName();
    void setName(QString* name);

private:
    qint32 id;
QString* name;
};

} /* namespace Swagger */

#endif /* SWGNetwork_H_ */
