#include "rice/Enum.hpp"
#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include "rice/ruby_try_catch.hpp"
#include "rice/to_from_ruby.hpp"

#include <Leap.h>


template <typename Type>
VALUE initialize_copy(VALUE self, VALUE other) {
  Type *data = static_cast<Type *>(DATA_PTR(other));
  DATA_PTR(self) = new Type(*data);
  return self;

}

using namespace Leap;
template VALUE initialize_copy<CircleGesture>(VALUE, VALUE);
template VALUE initialize_copy<Config>(VALUE, VALUE);
template VALUE initialize_copy<Controller>(VALUE, VALUE);
template VALUE initialize_copy<Device>(VALUE, VALUE);
template VALUE initialize_copy<DeviceList>(VALUE, VALUE);
template VALUE initialize_copy<Finger>(VALUE, VALUE);
template VALUE initialize_copy<FingerList>(VALUE, VALUE);
template VALUE initialize_copy<FloatArray>(VALUE, VALUE);
template VALUE initialize_copy<Frame>(VALUE, VALUE);
template VALUE initialize_copy<Gesture>(VALUE, VALUE);
template VALUE initialize_copy<GestureList>(VALUE, VALUE);
template VALUE initialize_copy<Hand>(VALUE, VALUE);
template VALUE initialize_copy<HandList>(VALUE, VALUE);
template VALUE initialize_copy<InteractionBox>(VALUE, VALUE);
template VALUE initialize_copy<KeyTapGesture>(VALUE, VALUE);
template VALUE initialize_copy<Listener>(VALUE, VALUE);
template VALUE initialize_copy<Matrix>(VALUE, VALUE);
template VALUE initialize_copy<Pointable>(VALUE, VALUE);
template VALUE initialize_copy<PointableList>(VALUE, VALUE);
template VALUE initialize_copy<Screen>(VALUE, VALUE);
template VALUE initialize_copy<ScreenList>(VALUE, VALUE);
template VALUE initialize_copy<ScreenTapGesture>(VALUE, VALUE);
template VALUE initialize_copy<SwipeGesture>(VALUE, VALUE);
template VALUE initialize_copy<Tool>(VALUE, VALUE);
template VALUE initialize_copy<ToolList>(VALUE, VALUE);
template VALUE initialize_copy<Vector>(VALUE, VALUE);

float Vector_x_reader(const Vector &self) {
  return self.x;
}
void Vector_x_writer(Vector &self, float _x) {
  self.x = _x;
}
float Vector_y_reader(const Vector &self) {
  return self.y;
}
void Vector_y_writer(Vector &self, float _x) {
  self.y = _x;
}
float Vector_z_reader(const Vector &self) {
  return self.z;
}
void Vector_z_writer(Vector &self, float _x) {
  self.z = _x;
}
Vector Matrix_origin_reader(const Matrix &self) {
  return self.origin;
}
void Matrix_origin_writer(Matrix &self, Vector _x) {
  self.origin = _x;
}
Vector Matrix_xBasis_reader(const Matrix &self) {
  return self.xBasis;
}
void Matrix_xBasis_writer(Matrix &self, Vector _x) {
  self.xBasis = _x;
}
Vector Matrix_yBasis_reader(const Matrix &self) {
  return self.yBasis;
}
void Matrix_yBasis_writer(Matrix &self, Vector _x) {
  self.yBasis = _x;
}
Vector Matrix_zBasis_reader(const Matrix &self) {
  return self.zBasis;
}
void Matrix_zBasis_writer(Matrix &self, Vector _x) {
  self.zBasis = _x;
}

extern "C"
void Init_leap(void)
{
  RUBY_TRY
  {

    Rice::Module rb_mLeap = Rice::define_module("Leap");

    Rice::Data_Type<CircleGesture> rb_CircleGesture = Rice::define_class_under<CircleGesture, Gesture>(rb_mLeap, "CircleGesture");
    rb_CircleGesture.define_constructor(Rice::Constructor<CircleGesture>());
    rb_CircleGesture.define_method("center", &CircleGesture::center);
    rb_CircleGesture.define_method("normal", &CircleGesture::normal);
    rb_CircleGesture.define_method("pointable", &CircleGesture::pointable);
    rb_CircleGesture.define_method("progress", &CircleGesture::progress);
    rb_CircleGesture.define_method("radius", &CircleGesture::radius);
    rb_CircleGesture.define_singleton_method("classType", &CircleGesture::classType);

    Rice::Data_Type<Config> rb_Config = Rice::define_class<Config>("Config");
    rb_define_method(rb_Config.value(), "initialize_copy", RUBY_METHOD_FUNC(initialize_copy<Config>), 1);

    Rice::Enum<Config::ValueType> rb_ValueType = Rice::define_enum<Config::ValueType>("ValueType", rb_Config);
    rb_ValueType.define_value("TYPE_UNKNOWN", Config::TYPE_UNKNOWN);
    rb_ValueType.define_value("TYPE_BOOLEAN", Config::TYPE_BOOLEAN);
    rb_ValueType.define_value("TYPE_INT32", Config::TYPE_INT32);
    rb_ValueType.define_value("TYPE_FLOAT", Config::TYPE_FLOAT);
    rb_ValueType.define_value("TYPE_STRING", Config::TYPE_STRING);

    rb_Config.define_constructor(Rice::Constructor<Config>());
    rb_Config.define_method("getBool", &Config::getBool);
    rb_Config.define_method("getFloat", &Config::getFloat);
    rb_Config.define_method("getInt32", &Config::getInt32);
    rb_Config.define_method("getString", &Config::getString);
    rb_Config.define_method("save", &Config::save);
    rb_Config.define_method("setBool", &Config::setBool);
    rb_Config.define_method("setFloat", &Config::setFloat);
    rb_Config.define_method("setInt32", &Config::setInt32);
    rb_Config.define_method("setString", &Config::setString);
    rb_Config.define_method("type", &Config::type);


    Rice::Data_Type<Controller> rb_Controller = Rice::define_class<Controller>("Controller");
    rb_define_method(rb_Controller.value(), "initialize_copy", RUBY_METHOD_FUNC(initialize_copy<Controller>), 1);

    Rice::Enum<Controller::PolicyFlag> rb_PolicyFlag = Rice::define_enum<Controller::PolicyFlag>("PolicyFlag", rb_Controller);
    rb_PolicyFlag.define_value("POLICY_DEFAULT", Controller::POLICY_DEFAULT);
    rb_PolicyFlag.define_value("POLICY_BACKGROUND_FRAMES", Controller::POLICY_BACKGROUND_FRAMES);
    rb_Controller.define_constructor(Rice::Constructor<Controller>());

    rb_Controller.define_method("addListener", &Controller::addListener);
    rb_Controller.define_method("calibratedScreens", &Controller::calibratedScreens);
    rb_Controller.define_method("config", &Controller::config);
    rb_Controller.define_method("devices", &Controller::devices);
    rb_Controller.define_method("enableGesture", &Controller::enableGesture);
    rb_Controller.define_method("frame", &Controller::frame);
    rb_Controller.define_method("hasFocus", &Controller::hasFocus);
    rb_Controller.define_method("isConnected", &Controller::isConnected);
    rb_Controller.define_method("isGestureEnabled", &Controller::isGestureEnabled);
    rb_Controller.define_method("locatedScreens", &Controller::locatedScreens);
    rb_Controller.define_method("policyFlags", &Controller::policyFlags);
    rb_Controller.define_method("removeListener", &Controller::removeListener);
    rb_Controller.define_method("setPolicyFlags", &Controller::setPolicyFlags);


    Rice::Data_Type<Device> rb_Device = Rice::define_class<Device>("Device");
    rb_define_method(rb_Device.value(), "initialize_copy", RUBY_METHOD_FUNC(initialize_copy<Device>), 1);
    rb_Device.define_constructor(Rice::Constructor<Device>());
    rb_Device.define_method("distanceToBoundary", &Device::distanceToBoundary);
    rb_Device.define_method("horizontalViewAngle", &Device::horizontalViewAngle);
    rb_Device.define_method("isValid", &Device::isValid);
    rb_Device.define_method("range", &Device::range);
    rb_Device.define_method("to_s", &Device::toString);
    rb_Device.define_method("verticalViewAngle", &Device::verticalViewAngle);
    rb_Device.define_method("!=", &Device::operator !=);
    rb_Device.define_method("==", &Device::operator ==);
    rb_Device.define_singleton_method("invalid", &Device::invalid);



    Rice::Data_Type<DeviceList> rb_DeviceList = Rice::define_class<DeviceList>("DeviceList");
    rb_define_method(rb_DeviceList.value(), "initialize_copy", RUBY_METHOD_FUNC(initialize_copy<DeviceList>), 1);
    rb_DeviceList.define_constructor(Rice::Constructor<DeviceList>());
    rb_DeviceList.define_method("empty?", &DeviceList::isEmpty);
    rb_DeviceList.define_method("size", &DeviceList::count);
    rb_DeviceList.define_method("append", &DeviceList::append);
    rb_DeviceList.define_method("[]", &DeviceList::operator []);


    Rice::Data_Type<Finger> rb_Finger = Rice::define_class_under<Finger, Pointable>(rb_mLeap, "Finger");
    rb_Finger.define_constructor(Rice::Constructor<Finger>());
    rb_Finger.define_method("to_s", &Finger::toString);
    rb_Finger.define_singleton_method("invalid", &Finger::invalid);
    Rice::Data_Type<FingerList> rb_FingerList = Rice::define_class<FingerList>("FingerList");
    rb_define_method(rb_FingerList.value(), "initialize_copy", RUBY_METHOD_FUNC(initialize_copy<FingerList>), 1);
    rb_FingerList.define_constructor(Rice::Constructor<FingerList>());
    rb_FingerList.define_method("empty?", &FingerList::isEmpty);
    rb_FingerList.define_method("size", &FingerList::count);
    rb_FingerList.define_method("append", &FingerList::append);
    rb_FingerList.define_method("[]", &FingerList::operator []);

    rb_FingerList.define_method("frontmost", &FingerList::frontmost);
    rb_FingerList.define_method("leftmost", &FingerList::leftmost);

    Rice::Data_Type<FloatArray> rb_FloatArray = Rice::define_class<FloatArray>("FloatArray");
    rb_define_method(rb_FloatArray.value(), "initialize_copy", RUBY_METHOD_FUNC(initialize_copy<FloatArray>), 1);
    rb_FloatArray.define_constructor(Rice::Constructor<FloatArray>());
    rb_FloatArray.define_method("[]", &FloatArray::operator []);

    Rice::Data_Type<Frame> rb_Frame = Rice::define_class<Frame>("Frame");
    rb_define_method(rb_Frame.value(), "initialize_copy", RUBY_METHOD_FUNC(initialize_copy<Frame>), 1);
    rb_Frame.define_constructor(Rice::Constructor<Frame>());
    rb_Frame.define_method("currentFramesPerSecond", &Frame::currentFramesPerSecond);
    rb_Frame.define_method("finger", &Frame::finger);
    rb_Frame.define_method("fingers", &Frame::fingers);
    rb_Frame.define_method("gesture", &Frame::gesture);

    rb_Frame.define_method("hand", &Frame::hand);
    rb_Frame.define_method("hands", &Frame::hands);
    rb_Frame.define_method("id", &Frame::id);
    rb_Frame.define_method("interactionBox", &Frame::interactionBox);
    rb_Frame.define_method("isValid", &Frame::isValid);
    rb_Frame.define_method("pointable", &Frame::pointable);
    rb_Frame.define_method("pointables", &Frame::pointables);


    rb_Frame.define_method("rotationAxis", &Frame::rotationAxis);
    rb_Frame.define_method("rotationMatrix", &Frame::rotationMatrix);
    rb_Frame.define_method("rotationProbability", &Frame::rotationProbability);
    rb_Frame.define_method("scaleFactor", &Frame::scaleFactor);
    rb_Frame.define_method("scaleProbability", &Frame::scaleProbability);
    rb_Frame.define_method("timestamp", &Frame::timestamp);
    rb_Frame.define_method("tool", &Frame::tool);
    rb_Frame.define_method("tools", &Frame::tools);
    rb_Frame.define_method("to_s", &Frame::toString);
    rb_Frame.define_method("translation", &Frame::translation);
    rb_Frame.define_method("translationProbability", &Frame::translationProbability);
    rb_Frame.define_method("!=", &Frame::operator !=);
    rb_Frame.define_method("==", &Frame::operator ==);
    rb_Frame.define_singleton_method("invalid", &Frame::invalid);



    Rice::Data_Type<Gesture> rb_Gesture = Rice::define_class<Gesture>("Gesture");
    rb_define_method(rb_Gesture.value(), "initialize_copy", RUBY_METHOD_FUNC(initialize_copy<Gesture>), 1);
    Rice::Enum<Gesture::State> rb_State = Rice::define_enum<Gesture::State>("State", rb_Gesture);
    Rice::Enum<Gesture::Type> rb_Type = Rice::define_enum<Gesture::Type>("Type", rb_Gesture);
    rb_State.define_value("STATE_INVALID", Gesture::STATE_INVALID);
    rb_State.define_value("STATE_START", Gesture::STATE_START);
    rb_State.define_value("STATE_UPDATE", Gesture::STATE_UPDATE);
    rb_State.define_value("STATE_STOP", Gesture::STATE_STOP);
    rb_Type.define_value("TYPE_INVALID", Gesture::TYPE_INVALID);
    rb_Type.define_value("TYPE_SWIPE", Gesture::TYPE_SWIPE);
    rb_Type.define_value("TYPE_CIRCLE", Gesture::TYPE_CIRCLE);
    rb_Type.define_value("TYPE_SCREEN_TAP", Gesture::TYPE_SCREEN_TAP);
    rb_Type.define_value("TYPE_KEY_TAP", Gesture::TYPE_KEY_TAP);
    rb_Gesture.define_constructor(Rice::Constructor<Gesture>());
    rb_Gesture.define_method("duration", &Gesture::duration);
    rb_Gesture.define_method("durationSeconds", &Gesture::durationSeconds);
    rb_Gesture.define_method("frame", &Gesture::frame);
    rb_Gesture.define_method("hands", &Gesture::hands);
    rb_Gesture.define_method("id", &Gesture::id);
    rb_Gesture.define_method("isValid", &Gesture::isValid);
    rb_Gesture.define_method("!=", &Gesture::operator !=);
    rb_Gesture.define_method("==", &Gesture::operator ==);
    rb_Gesture.define_method("pointables", &Gesture::pointables);
    rb_Gesture.define_method("state", &Gesture::state);
    rb_Gesture.define_method("to_s", &Gesture::toString);
    rb_Gesture.define_method("type", &Gesture::type);
    rb_Gesture.define_singleton_method("invalid", &Gesture::invalid);

    Rice::Data_Type<GestureList> rb_GestureList = Rice::define_class<GestureList>("GestureList");
    rb_define_method(rb_GestureList.value(), "initialize_copy", RUBY_METHOD_FUNC(initialize_copy<GestureList>), 1);
    rb_GestureList.define_constructor(Rice::Constructor<GestureList>());
    rb_GestureList.define_method("empty?", &GestureList::isEmpty);
    rb_GestureList.define_method("size", &GestureList::count);
    rb_GestureList.define_method("append", &GestureList::append);
    rb_GestureList.define_method("[]", &GestureList::operator []);

    Rice::Data_Type<Hand> rb_Hand = Rice::define_class<Hand>("Hand");
    rb_define_method(rb_Hand.value(), "initialize_copy", RUBY_METHOD_FUNC(initialize_copy<Hand>), 1);
    rb_Hand.define_constructor(Rice::Constructor<Hand>());
    rb_Hand.define_method("direction", &Hand::direction);
    rb_Hand.define_method("finger", &Hand::finger);
    rb_Hand.define_method("fingers", &Hand::fingers);
    rb_Hand.define_method("frame", &Hand::frame);
    rb_Hand.define_method("id", &Hand::id);
    rb_Hand.define_method("isValid", &Hand::isValid);
    rb_Hand.define_method("!=", &Hand::operator !=);
    rb_Hand.define_method("==", &Hand::operator ==);
    rb_Hand.define_method("palmNormal", &Hand::palmNormal);
    rb_Hand.define_method("palmPosition", &Hand::palmPosition);
    rb_Hand.define_method("palmVelocity", &Hand::palmVelocity);
    rb_Hand.define_method("pointable", &Hand::pointable);
    rb_Hand.define_method("pointables", &Hand::pointables);

    rb_Hand.define_method("rotationAxis", &Hand::rotationAxis);
    rb_Hand.define_method("rotationMatrix", &Hand::rotationMatrix);
    rb_Hand.define_method("rotationProbability", &Hand::rotationProbability);
    rb_Hand.define_method("scaleFactor", &Hand::scaleFactor);
    rb_Hand.define_method("scaleProbability", &Hand::scaleProbability);
    rb_Hand.define_method("sphereCenter", &Hand::sphereCenter);
    rb_Hand.define_method("sphereRadius", &Hand::sphereRadius);
    rb_Hand.define_method("stabilizedPalmPosition", &Hand::stabilizedPalmPosition);
    rb_Hand.define_method("timeVisible", &Hand::timeVisible);
    rb_Hand.define_method("tool", &Hand::tool);
    rb_Hand.define_method("tools", &Hand::tools);
    rb_Hand.define_method("to_s", &Hand::toString);
    rb_Hand.define_method("translation", &Hand::translation);
    rb_Hand.define_method("translationProbability", &Hand::translationProbability);
    rb_Hand.define_singleton_method("invalid", &Hand::invalid);

    Rice::Data_Type<HandList> rb_HandList = Rice::define_class<HandList>("HandList");
    rb_define_method(rb_HandList.value(), "initialize_copy", RUBY_METHOD_FUNC(initialize_copy<HandList>), 1);
    rb_HandList.define_constructor(Rice::Constructor<HandList>());
    rb_HandList.define_method("empty?", &HandList::isEmpty);
    rb_HandList.define_method("size", &HandList::count);
    rb_HandList.define_method("append", &HandList::append);
    rb_HandList.define_method("[]", &HandList::operator []);
    rb_HandList.define_method("frontmost", &HandList::frontmost);
    rb_HandList.define_method("leftmost", &HandList::leftmost);
    rb_HandList.define_method("rightmost", &HandList::rightmost);


    Rice::Data_Type<InteractionBox> rb_InteractionBox = Rice::define_class<InteractionBox>("InteractionBox");
    rb_define_method(rb_InteractionBox.value(), "initialize_copy", RUBY_METHOD_FUNC(initialize_copy<InteractionBox>), 1);
    rb_InteractionBox.define_constructor(Rice::Constructor<InteractionBox>());
    rb_InteractionBox.define_method("center", &InteractionBox::center);
    rb_InteractionBox.define_method("denormalizePoint", &InteractionBox::denormalizePoint);
    rb_InteractionBox.define_method("depth", &InteractionBox::depth);
    rb_InteractionBox.define_method("height", &InteractionBox::height);
    rb_InteractionBox.define_method("isValid", &InteractionBox::isValid);
    rb_InteractionBox.define_method("normalizePoint", &InteractionBox::normalizePoint);
    rb_InteractionBox.define_method("!=", &InteractionBox::operator !=);
    rb_InteractionBox.define_method("==", &InteractionBox::operator ==);
    rb_InteractionBox.define_method("to_s", &InteractionBox::toString);
    rb_InteractionBox.define_method("width", &InteractionBox::width);
    rb_InteractionBox.define_singleton_method("invalid", &InteractionBox::invalid);


    Rice::Data_Type<KeyTapGesture> rb_KeyTapGesture = Rice::define_class_under<KeyTapGesture, Gesture>(rb_mLeap, "KeyTapGesture");
    rb_KeyTapGesture.define_constructor(Rice::Constructor<KeyTapGesture>());
    rb_KeyTapGesture.define_method("direction", &KeyTapGesture::direction);
    rb_KeyTapGesture.define_method("pointable", &KeyTapGesture::pointable);
    rb_KeyTapGesture.define_method("position", &KeyTapGesture::position);
    rb_KeyTapGesture.define_method("progress", &KeyTapGesture::progress);

    Rice::Data_Type<Listener> rb_Listener = Rice::define_class<Listener>("Listener");
    rb_define_method(rb_Listener.value(), "initialize_copy", RUBY_METHOD_FUNC(initialize_copy<Listener>), 1);
    rb_Listener.define_constructor(Rice::Constructor<Listener>());
    rb_Listener.define_method("onConnect", &Listener::onConnect);
    rb_Listener.define_method("onDisconnect", &Listener::onDisconnect);
    rb_Listener.define_method("onExit", &Listener::onExit);
    rb_Listener.define_method("onFocusGained", &Listener::onFocusGained);
    rb_Listener.define_method("onFocusLost", &Listener::onFocusLost);
    rb_Listener.define_method("onFrame", &Listener::onFrame);
    rb_Listener.define_method("onInit", &Listener::onInit);

    Rice::Data_Type<Matrix> rb_Matrix = Rice::define_class<Matrix>("Matrix");
    rb_define_method(rb_Matrix.value(), "initialize_copy", RUBY_METHOD_FUNC(initialize_copy<Matrix>), 1);

    rb_Matrix.define_constructor(Rice::Constructor<Matrix>());
    rb_Matrix.define_method("!=", &Matrix::operator !=);
    rb_Matrix.define_method("*", &Matrix::operator *);
    rb_Matrix.define_method("*=", &Matrix::operator *=);
    rb_Matrix.define_method("==", &Matrix::operator ==);
    rb_Matrix.define_method("rigidInverse", &Matrix::rigidInverse);
    rb_Matrix.define_method("setRotation", &Matrix::setRotation);
    rb_Matrix.define_method("to_s", &Matrix::toString);
    rb_Matrix.define_method("transformDirection", &Matrix::transformDirection);
    rb_Matrix.define_method("transformPoint", &Matrix::transformPoint);

    rb_Matrix.define_singleton_method("identity", &Matrix::identity);

    rb_Matrix.define_method("origin", Matrix_origin_reader);
    rb_Matrix.define_method("origin=", Matrix_origin_writer);
    rb_Matrix.define_method("xBasis", Matrix_xBasis_reader);
    rb_Matrix.define_method("xBasis=", Matrix_xBasis_writer);
    rb_Matrix.define_method("yBasis", Matrix_yBasis_reader);
    rb_Matrix.define_method("yBasis=", Matrix_yBasis_writer);
    rb_Matrix.define_method("zBasis", Matrix_zBasis_reader);
    rb_Matrix.define_method("zBasis=", Matrix_zBasis_writer);

    Rice::Data_Type<Pointable> rb_Pointable = Rice::define_class<Pointable>("Pointable");
    rb_define_method(rb_Pointable.value(), "initialize_copy", RUBY_METHOD_FUNC(initialize_copy<Pointable>), 1);
    rb_Pointable.define_constructor(Rice::Constructor<Pointable>());
    rb_Pointable.define_method("direction", &Pointable::direction);
    rb_Pointable.define_method("frame", &Pointable::frame);
    rb_Pointable.define_method("hand", &Pointable::hand);
    rb_Pointable.define_method("id", &Pointable::id);
    rb_Pointable.define_method("isFinger", &Pointable::isFinger);
    rb_Pointable.define_method("isTool", &Pointable::isTool);
    rb_Pointable.define_method("isValid", &Pointable::isValid);
    rb_Pointable.define_method("length", &Pointable::length);
    rb_Pointable.define_method("!=", &Pointable::operator !=);
    rb_Pointable.define_method("==", &Pointable::operator ==);
    rb_Pointable.define_method("stabilizedTipPosition", &Pointable::stabilizedTipPosition);
    rb_Pointable.define_method("timeVisible", &Pointable::timeVisible);
    rb_Pointable.define_method("tipPosition", &Pointable::tipPosition);
    rb_Pointable.define_method("tipVelocity", &Pointable::tipVelocity);
    rb_Pointable.define_method("to_s", &Pointable::toString);
    rb_Pointable.define_method("touchDistance", &Pointable::touchDistance);
    rb_Pointable.define_method("touchZone", &Pointable::touchZone);
    rb_Pointable.define_method("width", &Pointable::width);
    rb_Pointable.define_singleton_method("invalid", &Pointable::invalid);

    Rice::Data_Type<PointableList> rb_PointableList = Rice::define_class<PointableList>("PointableList");
    rb_define_method(rb_PointableList.value(), "initialize_copy", RUBY_METHOD_FUNC(initialize_copy<PointableList>), 1);
    rb_PointableList.define_constructor(Rice::Constructor<PointableList>());
    rb_PointableList.define_method("empty?", &PointableList::isEmpty);
    rb_PointableList.define_method("size", &PointableList::count);
    //TODO: rb_PointableList.define_method("append", &PointableList::append);
    rb_PointableList.define_method("[]", &PointableList::operator []);
    rb_PointableList.define_method("frontmost", &PointableList::frontmost);
    rb_PointableList.define_method("leftmost", &PointableList::leftmost);
    rb_PointableList.define_method("rightmost", &PointableList::rightmost);

    Rice::Data_Type<Screen> rb_Screen = Rice::define_class<Screen>("Screen");
    rb_define_method(rb_Screen.value(), "initialize_copy", RUBY_METHOD_FUNC(initialize_copy<Screen>), 1);
    rb_Screen.define_method("bottomLeftCorner", &Screen::bottomLeftCorner);
    rb_Screen.define_method("distanceToPoint", &Screen::distanceToPoint);
    rb_Screen.define_method("heightPixels", &Screen::heightPixels);
    rb_Screen.define_method("horizontalAxis", &Screen::horizontalAxis);
    rb_Screen.define_method("id", &Screen::id);

    rb_Screen.define_method("isValid", &Screen::isValid);
    rb_Screen.define_method("normal", &Screen::normal);
    rb_Screen.define_method("!=", &Screen::operator !=);
    rb_Screen.define_method("==", &Screen::operator ==);

    rb_Screen.define_method("project", &Screen::project);
    rb_Screen.define_method("to_s", &Screen::toString);
    rb_Screen.define_method("verticalAxis", &Screen::verticalAxis);
    rb_Screen.define_method("widthPixels", &Screen::widthPixels);
    rb_Screen.define_singleton_method("invalid", &Screen::invalid);

    Rice::Data_Type<ScreenList> rb_ScreenList = Rice::define_class<ScreenList>("ScreenList");
    rb_define_method(rb_ScreenList.value(), "initialize_copy", RUBY_METHOD_FUNC(initialize_copy<ScreenList>), 1);
    rb_ScreenList.define_constructor(Rice::Constructor<ScreenList>());
    rb_ScreenList.define_method("empty?", &ScreenList::isEmpty);
    rb_ScreenList.define_method("size", &ScreenList::count);
    rb_ScreenList.define_method("[]", &ScreenList::operator []);
    rb_ScreenList.define_method("closestScreen", &ScreenList::closestScreen);
        // TODO: rb_ScreenList.define_method("closestScreenHit", &ScreenList::closestScreenHit);


    Rice::Data_Type<ScreenTapGesture> rb_ScreenTapGesture = Rice::define_class_under<ScreenTapGesture, Gesture>(rb_mLeap, "ScreenTapGesture");
    rb_ScreenTapGesture.define_constructor(Rice::Constructor<ScreenTapGesture>());

    rb_ScreenTapGesture.define_method("direction", &ScreenTapGesture::direction);
    rb_ScreenTapGesture.define_method("pointable", &ScreenTapGesture::pointable);
    rb_ScreenTapGesture.define_method("position", &ScreenTapGesture::position);
    rb_ScreenTapGesture.define_method("progress", &ScreenTapGesture::progress);
    rb_ScreenTapGesture.define_singleton_method("classType", &ScreenTapGesture::classType);

    Rice::Data_Type<SwipeGesture> rb_SwipeGesture = Rice::define_class_under<SwipeGesture, Gesture>(rb_mLeap, "SwipeGesture");
    rb_SwipeGesture.define_constructor(Rice::Constructor<SwipeGesture>());
    rb_SwipeGesture.define_method("direction", &SwipeGesture::direction);
    rb_SwipeGesture.define_method("pointable", &SwipeGesture::pointable);
    rb_SwipeGesture.define_method("position", &SwipeGesture::position);
    rb_SwipeGesture.define_method("speed", &SwipeGesture::speed);
    rb_SwipeGesture.define_method("startPosition", &SwipeGesture::startPosition);
    rb_ScreenTapGesture.define_singleton_method("classType", &ScreenTapGesture::classType);

    Rice::Data_Type<Tool> rb_Tool = Rice::define_class_under<Tool, Pointable>(rb_mLeap, "Tool");
    rb_Tool.define_constructor(Rice::Constructor<Tool>());
    rb_Tool.define_method("to_s", &Tool::toString);
    rb_Tool.define_singleton_method("invalid", &Tool::invalid);

    Rice::Data_Type<ToolList> rb_ToolList = Rice::define_class<ToolList>("ToolList");
    rb_define_method(rb_ToolList.value(), "initialize_copy", RUBY_METHOD_FUNC(initialize_copy<ToolList>), 1);
    rb_ToolList.define_constructor(Rice::Constructor<ToolList>());
    rb_ToolList.define_method("empty?", &ToolList::isEmpty);
    rb_ToolList.define_method("size", &ToolList::count);
    rb_ToolList.define_method("append", &ToolList::append);
    rb_ToolList.define_method("[]", &ToolList::operator []);
    rb_ToolList.define_method("frontmost", &ToolList::frontmost);
    rb_ToolList.define_method("leftmost", &ToolList::leftmost);
    rb_ToolList.define_method("rightmost", &ToolList::rightmost);

    Rice::Data_Type<Vector> rb_Vector = Rice::define_class<Vector>("Vector");
    rb_define_method(rb_Vector.value(), "initialize_copy", RUBY_METHOD_FUNC(initialize_copy<Vector>), 1);
    rb_Vector.define_constructor(Rice::Constructor<Vector>());
    rb_Vector.define_method("angleTo", &Vector::angleTo);
    rb_Vector.define_method("cross", &Vector::cross);
    rb_Vector.define_method("distanceTo", &Vector::distanceTo);
    rb_Vector.define_method("dot", &Vector::dot);
    rb_Vector.define_method("isValid", &Vector::isValid);
    rb_Vector.define_method("magnitude", &Vector::magnitude);
    rb_Vector.define_method("magnitudeSquared", &Vector::magnitudeSquared);
    rb_Vector.define_method("normalized", &Vector::normalized);
    rb_Vector.define_method("!=", &Vector::operator !=);
    rb_Vector.define_method("*", &Vector::operator *);
    rb_Vector.define_method("*=", &Vector::operator *=);
    rb_Vector.define_method("+", &Vector::operator +);
    rb_Vector.define_method("+=", &Vector::operator +=);

    rb_Vector.define_method("-=", &Vector::operator -=);
    rb_Vector.define_method("/", &Vector::operator /);
    rb_Vector.define_method("/=", &Vector::operator /=);
    rb_Vector.define_method("==", &Vector::operator ==);
    rb_Vector.define_method("[]", &Vector::operator []);

    rb_Vector.define_method("pitch", &Vector::pitch);
    rb_Vector.define_method("roll", &Vector::roll);

    rb_Vector.define_method("to_s", &Vector::toString);

    rb_Vector.define_method("yaw", &Vector::yaw);
    rb_Vector.define_singleton_method("backward", &Vector::backward);
    rb_Vector.define_singleton_method("down", &Vector::down);
    rb_Vector.define_singleton_method("forward", &Vector::forward);
    rb_Vector.define_singleton_method("left", &Vector::left);
    rb_Vector.define_singleton_method("right", &Vector::right);
    rb_Vector.define_singleton_method("up", &Vector::up);
    rb_Vector.define_singleton_method("xAxis", &Vector::xAxis);
    rb_Vector.define_singleton_method("yAxis", &Vector::yAxis);
    rb_Vector.define_singleton_method("zAxis", &Vector::zAxis);
    rb_Vector.define_singleton_method("zero", &Vector::zero);
    rb_Vector.define_method("x", Vector_x_reader);
    rb_Vector.define_method("x=", Vector_x_writer);
    rb_Vector.define_method("y", Vector_y_reader);
    rb_Vector.define_method("y=", Vector_y_writer);
    rb_Vector.define_method("z", Vector_z_reader);
    rb_Vector.define_method("z=", Vector_z_writer);
  }
  RUBY_CATCH
}
