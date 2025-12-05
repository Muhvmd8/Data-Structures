#pragma once
#include "StackUsingArray.h"
#include<iostream>
using namespace std;

class StackApplications
{
private:
	  static bool IsOpenedParenthesis(char c)
	{
		return c == '(';
	}
	  static bool IsClosedParenthesis(char c)
	{
		return c == ')';
	}
	  static bool IsOperator(char c)
	  {
		  return c == '+' || c == '-' || c == '*' || c == '/';
	  }
      static int Precedence(char op)
      {
          if (op == '+' || op == '-') return 1;
          if (op == '*' || op == '/') return 2;
          return 0;
      }
public:
	  static bool IsBalancedParenthesis(string text)
	  {
		  if (text.size() == 0)
			  return false;

		  Stack<char> stack(text.size());

		  for (auto c : text)
		  {
			  if (IsOpenedParenthesis(c))
				  stack.Push(c);

			  if (IsClosedParenthesis(c) && !stack.IsEmpty())
				  stack.Pop();
		  }

		  return stack.IsEmpty();
	  }
      static string ConvertToPostfix(string expr)
      {
          Stack<char> stack(expr.size());
          string output = "";

          for (char c : expr)
          {
              if (c == ' ') continue; 

              // Operand
              if (isalnum(c))
              {
                  output += c;
              }
              // Opening parenthesis
              else if (c == '(')
              {
                  stack.Push(c);
              }
              // Closing parenthesis
              else if (c == ')')
              {
                  while (!stack.IsEmpty() && stack.Top() != '(')
                  {
                      output += stack.Top();
                      stack.Pop();
                  }
                  stack.Pop(); // Pop '('
              }
              // Operator
              else if (IsOperator(c))
              {
                  while (!stack.IsEmpty() && Precedence(stack.Top()) >= Precedence(c))
                  {
                      output += stack.Top();
                      stack.Pop();
                  }
                  stack.Push(c);
              }
          }

          while (!stack.IsEmpty())
          {
              output += stack.Top();
              stack.Pop();
          }

          return output;
      }
};