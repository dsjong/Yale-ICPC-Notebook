/**
 * Author: Dion Ong
 * Source: KACTL
 * Description: Segment tree with ability to add or set values of large intervals, and compute max of intervals.
 * Can be changed to other things (modify T, unit, f, and push).
 * Time: O(\log N).
 * Usage: Node* tr = new Node(L, R);
 * Node **tr = new Node*[MAXN]; //array of segtrees
 * for(int i=0; i<MAXN; i++) tr[i] = new Node(L, R);
 * Status: tested on napc21.icecreamcones, KACTL stress tests.
 */
struct Node{
    typedef int T;
    static constexpr T unset = INT_MIN, unit=0;
    T f(T a, T b) { return max(a, b); }
    T mset=unset, madd=0, val=unit; int lo, hi;
    Node *l=0, *r=0;
    Node(int lo, int hi): lo(lo), hi(hi){
        if(lo<hi){
            int mid=(lo+hi)/2;
            l=new Node(lo, mid); r=new Node(mid+1, hi);
        }
    }
    T query(int L, int R){
        if(L>R) return unit;
        push();
        if(R<lo || hi<L) return unit; //sentinel
        if(L<=lo && hi<=R) return val;
        return f(l->query(L, R), r->query(L, R));
    }
    void set(int L, int R, T x, int t=1){
        if(L>R) return;
        push();
        if(R<lo || hi<L) return;
        if(L<=lo && hi<=R){
            (t==1 ? mset : madd)=x;
            push(); return;
        }
        l->set(L, R, x, t), r->set(L, R, x, t);
        val=f(l->val, r->val);
    }
    void add(int L, int R, T x) { return set(L, R, x, 0); }
    void push(){
        mset!=unset ? val=mset : val+=madd; //mult (hi-lo+1) to BOTH for sum query
        if(l){ //if parent, push down
            if(mset!=unset){
                l->mset=r->mset=mset;
                l->madd=r->madd=0;
            }
            else if(madd){
                l->mset!=unset ? l->mset+=madd : l->madd+=madd;
                r->mset!=unset ? r->mset+=madd : r->madd+=madd;
            }
        }
        mset=unset, madd=0;
    }
};