WPCLI=wp
WPDIR=/data/data/com.termux/files/home/dev/wordpress/template
DOCDIR=./
SRC=$(DOCDIR)/notes.html
STATUS=publish
TITLE=gcc: mkdir
NAME=$(TITLE)
EXCERPT=$(shell  w3m -dump $(SRC)|head -n1)
DATE=
TYPE=post
CATEGORY=
PASSWORD=
FROMPOST=
TOPING=
PINGED=
MENUORDER=0
MIMETYPE=
GUID=`pwd`
TAGS_INPUT=
TAX_INPUT=
META_INPUT=
FIELD=
DB=testdb
DBUSER=root
DBPASS=
METAFILE=$(DOCDIR)/meta.json

.phony:\
	testdata\
	delete\
	wplist\
	dbcli\
	dbdrop\
	srchtml\
	cleanmeta
ifeq ($(wildcard $(METAFILE)),)
all:
	@printf "{\n\t\"id\":">$(DOCDIR)/meta.json
	@$(WPCLI) \
		post \
		create \
		$(SRC) \
		--post_status=$(STATUS)\
		--post_type=$(TYPE)\
		--post_title="$(TITLE)"\
		--post_name="$(NAME)"\
		--post_excerpt="$(EXCERPT)"\
		--post_category="$(CATEGORY)"\
		--post_date_gmt="$(DATE)"\
		--post_password="$(PASSWORD)"\
		--menu_order=$(MENUORDER)\
		--post_mime_type="$(MIMETYPE)"\
		--guid=$(GUID)\
		--tags_input=$(TAGS_INPUT)\
		--tax_input=$(TAX_INPUT)\
		--meta_input=$(META_INPUT)\
		--field=$(FIELD)\
		--porcelain\
		--path=$(WPDIR)>>$(DOCDIR)/meta.json
	@printf "}">>$(DOCDIR)/meta.json
	printf "Post created\n"
delete:
	@printf "No $(METAFILE), cannot delete post\n"
else
all:
	@$(WPCLI) \
		post \
		update \
		$(SRC) \
		`cat $(DOCDIR)/meta.json|jq -r '.id'`\
		--post_status=$(STATUS)\
		--post_type=$(TYPE)\
		--post_title="$(TITLE)"\
		--post_name="$(NAME)"\
		--post_excerpt="$(EXCERPT)"\
		--post_category="$(CATEGORY)"\
		--post_date_gmt="$(DATE)"\
		--post_password="$(PASSWORD)"\
		--menu_order=$(MENUORDER)\
		--post_mime_type="$(MIMETYPE)"\
		--guid=$(GUID)\
		--tags_input=$(TAGS_INPUT)\
		--tax_input=$(TAX_INPUT)\
		--meta_input=$(META_INPUT)\
		--field=$(FIELD)\
		--porcelain\
		--path=$(WPDIR)
delete:
	@$(WPCLI) \
		post \
		delete \
		`cat $(DOCDIR)/meta.json|jq -r '.id'`\
		--force\
		--path=$(WPDIR)
	@rm $(METAFILE)
endif
cleanmeta:
	rm $(METAFILE)
testdata:
	fortune > $(DOCDIR)/notes
srchtml:
	(enscript ../src/a.c -w html -p -)>>$(SRC)
wplist:
	@$(WPCLI) \
		post\
		list\
		--format=json\
		--path=$(WPDIR)\
		|\
		jq '.'
dbcli:
	mysql \
		--database=$(DB)\
		--user=$(DBUSER)\
		--password="$(DBPASS)"
dbdrop:
	mysql \
		--database=$(DB)\
		--user=$(DBUSER) \
		--password="$(DBPASS)"\
		-e "\
		use testdb;\
		delete a,b,c,d\
		FROM wp_posts a\
		LEFT JOIN wp_term_relationships b ON ( a.ID = b.object_id )\
		LEFT JOIN wp_postmeta c ON ( a.ID = c.post_id )\
		LEFT JOIN wp_term_taxonomy d ON ( d.term_taxonomy_id = b.term_taxonomy_id)\
		LEFT JOIN wp_terms e ON ( e.term_id = d.term_id );\
	"
	rm $(METAFILE)
