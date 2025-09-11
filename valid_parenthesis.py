class Solution:
    def isValid(self, s: str) -> bool:
        
        stack = []
        size=len(s)
        
        for i in s:
            if i=='(' or i=='{' or i=='[':
                if(len(stack)==size):
                    return False
                else:
                    stack.append(i)
            if i==')' or i=='}' or i==']':
                if(len(stack)==0):
                    return False
                
                if i==')':
                        if(stack[-1]=='('):
                            stack.pop()
                        else:
                            return False
                elif i=='}':
                        if(stack[-1]=='{'):
                            stack.pop()
                        else:
                            return False
                elif i==']':
                        if(stack[-1]=='['):
                            stack.pop()
                        else:
                            return False
        
        if(len(stack)==0):
            return True
        else:
            return False
                    '''

class Solution:
    def isValid(self, s: str) -> bool:
        i=0
        a=[]
        for i in range(len(s)):
            if s[i]=='('or s[i]=='['or s[i]=='{':
                a.append(s[i])
            else:
                if not a:
                    return False
                top=a.pop()
                if s[i]==')'and top!='(':
                    return False
                if s[i]==']'and top!='[':
                    return False
                if s[i]=='}'and top!='{':
                    return False
        return len(a)==0

            '''
         
        
        