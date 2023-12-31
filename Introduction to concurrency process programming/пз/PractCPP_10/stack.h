#pragma once
#include <iostream>
#include <stack>
#include <mutex>
#include <condition_variable>
#include <exception>
using namespace std;

struct empty_stack : exception
{
	const char* what() const throw() { return ""; }
};

template<typename T>
class threadsafe_stack {
	stack<T> data;
	mutable mutex m;
public:
	threadsafe_stack() {}
	threadsafe_stack(const threadsafe_stack& other)
	{
		lock_guard<mutex> lock(other.m);
		data = other.data;
	}

	threadsafe_stack& operator=(const threadsafe_stack&) = delete;

	void push(T new_value)
	{
		lock_guard<mutex> lock(m);
		data.push(move(new_value));
	}

	shared_ptr<T> pop()
	{
		lock_guard<mutex> lock(m);
		if (data.empty()) throw empty_stack();
		shared_ptr<T> const res(make_shared<T>(move(data.top())));
		data.pop();
		return res;
	}

	void pop(T& value)
	{
		lock_guard<mutex> lock(m);
		if (data.empty()) throw empty_stack();
		value = move(data.top());
		data.pop();
	}

	bool empty() const
	{
		lock_guard<mutex> lock(m);
		return data.empty();
	}
};