from django.contrib import admin
from .models import Author, Genre, Book, BookInstance, Language

# Register your models here.

# admin.site.register(Book)
# admin.site.register(Author)
# admin.site.register(BookInstance)
admin.site.register(Genre)
admin.site.register(Language)


class BooksInline(admin.TabularInline):
    extra = 0
    model = Book

# Define the admin class


class AuthorAdmin(admin.ModelAdmin):
    list_display = ('last_name', 'first_name',
                    'date_of_birth', 'date_of_death')

    fields = ['first_name', 'last_name', ('date_of_birth', 'date_of_death')]

    inlines = [BooksInline]


admin.site.register(Author, AuthorAdmin)


class BooksInstanceInline(admin.TabularInline):
    extra = 0
    model = BookInstance

# Register the Admin classes for Book using the decorator


class BookAdmin(admin.ModelAdmin):
    list_display = ('title', 'author', 'display_genre')
    inlines = [BooksInstanceInline]


admin.site.register(Book, BookAdmin)


# Register the Admin classes for BookInstance using the decorator
class BookInstanceAdmin(admin.ModelAdmin):
    list_display = ('book', 'status', 'due_back', 'id')
    list_filter = ('status', 'due_back')

    fieldsets = (
        (None, {
            'fields': ('book', 'imprint', 'id')
        }),
        ('Availability', {
            'fields': ('status', 'due_back',  'borrower')
        }),
    )


admin.site.register(BookInstance, BookInstanceAdmin)
