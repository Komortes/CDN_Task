#ifndef TESTS
#define TESTS

struct Test {
    const char *address;
    int expectedResult;
};

struct Test tests[] = {
    {"q.w.e.r.t.y.bbb.cc.d", 1}, // match to *.bbb.cc.d
    {"z.y.x.w.v.u", 0}, // no match
    {"g.h.i.j", 1}, // match to g.h.i.*
    {"a.b.c.j.k", 1}, // match to *.j.k
    {"random.net", 1}, // match to *.net
    {"some.website.co.uk", 1}, // match to *.co.uk
    {"website.com.br", 1}, // match to *.com.br
    {"m.n.o.p", 1}, // match to m.n.o.*
    {"domain.org", 1}, // match to *.org
    {"p.q.r", 1}, // match to p.q.*
    {"a.b.r.s.t.u", 1}, // match to *.r.s.t.u
    {"site.ac.jp", 1}, // match to *.ac.jp
    {"v.w.x.y", 1}, // match to v.w.x.*
    {"a.b.c.y.z", 1}, // match to *.y.z
    {"c.b.a.net", 1}, // match to *.net
    {"z.y.x.w.com", 1}, // match to *.com
    {"site.com.au", 1}, // match to *.com.au
    {"a.b.c.d.e", 1}, // match to *.e
    {"c.b.a.co.nz", 1}, // match to *.nz
    {"b.a.org.uk", 1}, // match to *.uk
    {"e.f.g.h.i", 1}, // match to *.i
    {"b.a.ac.uk", 1}, // match to *.uk
    {"college.edu", 1}, // match to *.edu
    {"i.j.k.l", 1}, // match to *.l
    {"a.b.c.l.m.n.o", 1}, // match to *.o
    {"a.b.c.p.q.r.s", 1}, // match to *.s
    {"domain.eu", 1}, // match to *.eu
    {"site.gov", 1}, // match to *.gov
    {"site.mil", 1}, // match to *.mil
    {"t.u.v.w", 1}, // match to *.w
    {"domain.int", 1}, // match to *.int
    {"a.b.c.w.x.y.z", 1}, // match to *.z
    {"d.c.b.a.net", 1}, // match to *.net
    {"a.b.c.d.e.f", 1}, // match to *.f
    {"f.e.d.c.b.a.edu", 1}, // match to *.edu
    {"f.e.d.c.b.a.gov", 1}, // match to *.gov
    {"f.e.d.c.b.a.mil", 1}, // match to *.mil
    {"e.d.c.b.eu", 1}, // match to *.eu
    {"e.d.c.b.int", 1}, // match to *.int
    {"c.b.a.org", 1}, // match to *.org
    {"a.b.c.d", 1}, // match to a.*.c.d
    {"e.f.g.h", 1}, // match to e.*.g.h
    {"i.j.k.l", 1}, // match to i.*.k.l
    {"m.n.o.p", 1}, // match to m.*.o.p
    {"q.r.s.t", 1}, // match to q.*.s.t
    {"y.z.a.b", 1}, // match to y.*.a.b
    {"c.d.e.f", 1}, // match to c.*.e.f
    {"g.h.i.j", 1}, // match to g.*.i.j
};

#endif
