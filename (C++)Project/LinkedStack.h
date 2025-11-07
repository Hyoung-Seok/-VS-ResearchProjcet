#pragma once
#include <iostream>

template <typename T>
struct Node
{
	T data = 0;
	Node<T>* next = nullptr;
};

template <typename T>
class LinkedStack
{
public:
	LinkedStack()
	{
		head = new Node<T>();
	}
	~LinkedStack()
	{
		if (head->next != nullptr)
		{
			auto cur = head->next;
			while (cur != nullptr)
			{
				auto next = cur->next;
				delete cur;
				cur = next;
			}
		}

		delete head;
	}

	void Push(T data)
	{
		if (head == nullptr)
		{
			return;
		}

		auto newNode = new Node<T>();
		newNode->data = data;

		// 기존 노드 연결
		newNode->next = head->next;

		// 헤드 노드와 새 노드 연결
		head->next = newNode;
	}

	T Pop()
	{
		if (head == nullptr || IsEmpty() == true)
		{
			std::cout << "스택이 존재하지 않거나 꺼낼 데이터가 없습니다!" << std::endl;
			return -1;
		}

		auto result = head->next->data;
		auto delNode = head->next;

		head->next = delNode->next;
		delete delNode;

		return result;
	}

	T Peek()
	{
		if (head == nullptr || IsEmpty())
		{
			std::cout << "스택이 존재하지 않거나 꺼낼 데이터가 없습니다!" << std::endl;
			return -1;
		}

		return head->next->data;
	}

	bool IsEmpty()
	{
		return head->next == nullptr;
	}

private:
	Node<T>* head = nullptr;
};
