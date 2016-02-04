#include <nan.h>
#include "test.h"

MyWorker::MyWorker()
	: AsyncWorker(nullptr) { }

MyWorker::~MyWorker() { }

void MyWorker::Execute(){ }

void MyWorker::Run(const Nan::FunctionCallbackInfo<v8::Value>& info){
    auto resolver = Promise::Resolver::New(info.GetIsolate());
    auto worker = new MyWorker();
    worker->SaveToPersistent("key",resolver);
    AsyncQueueWorker(worker);
    info.GetReturnValue().Set(resolver->GetPromise());
}

void MyWorker::HandleOKCallback(){
    auto res = GetFromPersistent("key").As<v8::Promise::Resolver>();
    res->Resolve(Nan::Undefined());
}

void Init(v8::Local<v8::Object> exports, v8::Local<v8::Object> module) {
	Nan::SetMethod(module,"exports",MyWorker::Run);
}

NODE_MODULE(binding, Init)