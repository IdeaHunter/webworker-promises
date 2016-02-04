#pragma once

#include <nan.h>
using namespace v8;
using namespace Nan;

class  MyWorker: public AsyncWorker {
public: 
	MyWorker();
  	~MyWorker();
	void Execute();
	void HandleOKCallback();
	static void Run(const Nan::FunctionCallbackInfo<v8::Value>& info);
};