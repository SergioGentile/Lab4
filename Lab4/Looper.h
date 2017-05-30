#pragma once
#include <vector>
#include <queue>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <memory>
#include <iostream>
#include <stdexcept>


template<class T> class Looper
{	
	
private:
	std::thread *serveThread;
	std::queue<T> messageQueue; 
	std::mutex m_queue;
	std::condition_variable cv;
	bool exit;

public:
	Looper()
	{
		exit = false;
		serveThread = new std::thread(serveFunction, std::ref(m_queue), std::ref(cv), std::ref(messageQueue));
	};

	~Looper() {
		quit();
	};

	void Looper<T>::postMessage(T message) {
		if (exit == true) {
			throw std::exception("Il thread e' gia' stato chiuso.\n");
		}
		std::lock_guard<std::mutex> lk(m_queue);
		messageQueue.push(message);
		//std::cout << "inserisco qualcosa" << std::endl;
		cv.notify_one();
	};
	void quit() {
		messageQueue.push(Message("exit"));
		serveThread->join();
		exit = true;
	};

	static void serveFunction(std::mutex& m_queue, std::condition_variable& cv, std::queue<T>& messageQueue) {
		//Sarà da cambiare e metterlo a false
		T value;
		while (true) {
			std::unique_lock<std::mutex> lk(m_queue);
			cv.wait(lk, [&]() {return !messageQueue.empty(); });
			value = messageQueue.front();
			messageQueue.pop();
			lk.unlock();	
			if (value()<0) {
				break;
			}
		}
	};
};
