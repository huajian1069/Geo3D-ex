#include "meshModel.h"
#include <QString>
#include <QtCore/QDebug>
#include <QtCore/QString>
#include <QtWidgets/QLabel>
#include <Qt3DRender/QObjectPicker>
#include <Qt3DExtras/QTorusMesh>

extern QLabel *text;

SceneModifier::SceneModifier(Qt3DCore::QEntity *rootEntity)
    : m_rootEntity(rootEntity)
{
    // Mesh shape data
    Qt3DRender::QMesh *mesh = new Qt3DRender::QMesh();
    mesh->setSource(QUrl("qrc:/mesh/TrackML-PixelDetector.obj"));

    // Mesh Transform
    Qt3DCore::QTransform *meshTransform = new Qt3DCore::QTransform();
    meshTransform->setScale(0.011f);
    meshTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 0.0f));
    meshTransform->setTranslation(QVector3D(0.0f, 0.0f, 0.0f));

    // Mesh material
    Qt3DExtras::QPhongMaterial *meshMaterial = new Qt3DExtras::QPhongMaterial();
    meshMaterial->setDiffuse(QColor(QRgb(0xbeb32b)));

    // picker
    Qt3DRender::QObjectPicker *picker = new Qt3DRender::QObjectPicker();

    picker->setEnabled(true);

    // Mesh Entity
    m_meshEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_meshEntity->addComponent(mesh);
    m_meshEntity->addComponent(meshMaterial);
    m_meshEntity->addComponent(meshTransform);
    m_meshEntity->addComponent(picker);
    QObject::connect(picker, &Qt3DRender::QObjectPicker::clicked, this, &SceneModifier::onClicked);


    // Torus Mesh shape data
    Qt3DExtras::QTorusMesh *torusMesh = new Qt3DExtras::QTorusMesh();
    torusMesh->setRadius(1.0f);
    torusMesh->setMinorRadius(0.4f);
    torusMesh->setRings(100);
    torusMesh->setSlices(20);

    // Torus Mesh Transform
    Qt3DCore::QTransform *torusMeshTransform = new Qt3DCore::QTransform();
    torusMeshTransform->setScale(1.0f);
    torusMeshTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 0.0f));
    torusMeshTransform->setTranslation(QVector3D(10.0f, 10.0f, 0.0f));

    // Torus picker
    Qt3DRender::QObjectPicker *torusPicker = new Qt3DRender::QObjectPicker();
    torusPicker->setEnabled(true);

    // Torus Mesh Entity
    m_torusMeshEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_torusMeshEntity->addComponent(torusMesh);
    m_torusMeshEntity->addComponent(meshMaterial);
    m_torusMeshEntity->addComponent(torusMeshTransform);
    m_torusMeshEntity->addComponent(torusPicker);
    QObject::connect(torusPicker, &Qt3DRender::QObjectPicker::clicked, this, &SceneModifier::onClickedTorus);

}
SceneModifier::~SceneModifier()
{
}

void SceneModifier::onClicked(Qt3DRender::QPickEvent* event){
    Qt3DRender::QMesh *mesh =  (Qt3DRender::QMesh*)(m_meshEntity->componentsOfType<Qt3DRender::QMesh>()[0]);
    text->setText(QString("Something about Mesh: %1").arg(mesh->source()));
}

void SceneModifier::onClickedTorus(Qt3DRender::QPickEvent* event){
    Qt3DExtras::QTorusMesh *mesh =  (Qt3DExtras::QTorusMesh*)(m_torusMeshEntity->componentsOfType<Qt3DExtras::QTorusMesh>()[0]);
    text->setText(QString("Something about Mesh:\n radius = %1, rings = %2, slices=%3")
                  .arg(mesh->radius()).arg(mesh->rings()).arg(mesh->slices()));
}



void SceneModifier::enableMesh(bool enabled)
{
    m_meshEntity->setEnabled(enabled);
}
void SceneModifier::scaleMesh(int magnitude)
{
    float magnitudeF = 0.001 + (float)(magnitude) * 0.02 / 100.0;
    Qt3DCore::QTransform *transform =  (Qt3DCore::QTransform*)(m_meshEntity->componentsOfType<Qt3DCore::QTransform>()[0]);
    transform->setScale(magnitudeF);
}

void SceneModifier::rotateMeshX(int degree)
{
    float degreeF = degree * 360.0 / 100.0;
    Qt3DCore::QTransform *transform =  (Qt3DCore::QTransform*)(m_meshEntity->componentsOfType<Qt3DCore::QTransform>()[0]);
    transform->setRotationX(degreeF);
}
void SceneModifier::rotateMeshY(int degree)
{
    float degreeF = degree * 360.0 / 100.0;
    Qt3DCore::QTransform *transform =  (Qt3DCore::QTransform*)(m_meshEntity->componentsOfType<Qt3DCore::QTransform>()[0]);
    transform->setRotationY(degreeF);
}
void SceneModifier::rotateMeshZ(int degree)
{
    float degreeF = degree * 360.0 / 100.0;
    Qt3DCore::QTransform *transform =  (Qt3DCore::QTransform*)(m_meshEntity->componentsOfType<Qt3DCore::QTransform>()[0]);
    transform->setRotationZ(degreeF);
}





