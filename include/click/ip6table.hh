#ifndef IP6TABLE_HH
#define IP6TABLE_HH

// IP6 routing table.
// Lookup by longest prefix.
// Each entry contains a gateway and an output index.

#include <click/glue.hh>
#include <click/vector.hh>
#include <click/ip6address.hh>

class IP6Table { public:
  
  IP6Table();
  ~IP6Table();

  bool lookup(const IP6Address &dst, IP6Address &gw, int &index) const;
  
  void add(const IP6Address &dst, const IP6Address &mask, const IP6Address &gw, int index);
  void del(const IP6Address &dst, const IP6Address &mask);
  void clear()				{ _v.clear(); }

 private:
  
  struct Entry {
    IP6Address _dst;
    IP6Address _mask;
    IP6Address _gw;
    int _index;
    int _valid;
  };
  Vector<Entry> _v;
  
};

#endif
