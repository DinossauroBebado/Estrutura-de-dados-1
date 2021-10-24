#include "stack.c"

int main()
{
   Stack *p = create_stack(3);
   push(p, 1);
   push(p, 2);
   push(p, 4);
   while (!empty_stack(p))
   {
      printf("%d\n", pop(p));
   }
   free_stack(p);
   return 0;
}
