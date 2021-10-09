AvlTree Delete(int X,AvlTree T)
{Position Tmpell;
	if (T == NULL)
		FataError("Out of space!!!");
	else
		if (X < T->Data)
			T->Left = Delete(X, T->Left);
            if(Height(T->Right)-Height(T->Left)==2)
            if(X>T-Right->Data)
            T=SingleRotateWithRight(T);
            else
            T=DoubleRotateWithRight(T);
		else
			if (X > T->Data)
				T->Right = Delete(X, T->Left);
                if(Height(T->Left)-Height(T->Right)==2)
                if(X<T->Left->Data)
                T=SingleRotateWithLeft(T);
                else
                T=DoubleRotateWithLeft(T);

			else
				if (T->Left && T->Right)
				{
					Tmpell = FindMin(T->Right);
					T->Data = Tmpell->Data;
					T->Right = Delete(T->Data, T->Right);
				}
				else
				{
					Tmpell = T;
					if (T->Left == NULL)
					T = T->Right;
                    if(Height(T->Right)-Height(T->Left)==2)
                    if(X>T-Right->Data)
                    T=SingleRotateWithRight(T);
                    else
                    T=DoubleRotateWithRight(T);
					else
						if (T->Right == NULL)
							T = T->Left;
                            if(Height(T->Left)-Height(T->Right)==2)
                         if(X<T->Left->Data)
                        T=SingleRotateWithLeft(T);
                     else
                    T=DoubleRotateWithLeft(T);
					free(Tmpell);
				}
	return T;}
